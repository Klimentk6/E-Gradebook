#include "SubjectCollection.h"

SubjectCollection::SubjectCollection()
{
    nextId = 1;
    size = 0;
    capacity = MIN_CAPACITY;
    arr = new Subject[capacity];
}
SubjectCollection::SubjectCollection(const SubjectCollection& other)
{
    copyFrom(other);
}
SubjectCollection::SubjectCollection(SubjectCollection&& other) noexcept
{
    moveFrom(std::move(other));
}
SubjectCollection& SubjectCollection::operator=(const SubjectCollection& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}
SubjectCollection& SubjectCollection::operator=(SubjectCollection&& other) noexcept
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}
SubjectCollection::~SubjectCollection()
{
    delete[] arr;
    arr = nullptr;
}

void SubjectCollection::copyFrom(const SubjectCollection& other)
{
    nextId = other.nextId;
    size = other.size;
    capacity = other.capacity;
    arr = new Subject[capacity];
    for (unsigned i = 0; i < size; i++)
    {
        arr[i] = other.arr[i];
    }
}
void SubjectCollection::moveFrom(SubjectCollection&& other)
{
    nextId = other.nextId;
    size = other.size;
    capacity = other.capacity;
    arr = other.arr;
    other.arr = nullptr;
    other.size = 0;
    other.capacity = 0;
}
void SubjectCollection::free()
{
    delete[] arr;
    arr = nullptr;
}
void SubjectCollection::resize(unsigned newCapacity)
{
    capacity = newCapacity;
    Subject* temp = new Subject[capacity];
    for (unsigned i = 0; i < size; i++)
    {
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
}
unsigned SubjectCollection::calculateCapacity(unsigned requiredSize)
{
    unsigned newCapacity = requiredSize;

    if (newCapacity < MIN_CAPACITY)
    {
        newCapacity = MIN_CAPACITY;
    }

    newCapacity--;
    newCapacity |= newCapacity >> 1;
    newCapacity |= newCapacity >> 2;
    newCapacity |= newCapacity >> 4;
    newCapacity |= newCapacity >> 8;
    newCapacity |= newCapacity >> 16;
    newCapacity++;

    return newCapacity;
}
void SubjectCollection::shiftLeft(int index)
{
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}

void SubjectCollection::addSubject(const std::string& name, const std::string& teacherFullName, unsigned roomNumber)
{
    if (doesNameExist(name))
    {
        return;
    }

    if (size == capacity)
    {
        resize(capacity * RESIZE_COEFF);
    }

    Subject newSubject(nextId++, name, teacherFullName, roomNumber);

    unsigned insertIndex = 0;
    while (insertIndex < size && arr[insertIndex].getName() < name)
    {
        insertIndex++;
    }

    for (unsigned i = size; i > insertIndex; --i)
    {
        arr[i] = arr[i - 1];
    }

    arr[insertIndex] = newSubject;
    size++;
}
void SubjectCollection::editSubjectName(const std::string& oldName, const std::string& newName)
{
    Subject* subject = getSubjectByName(oldName);
    if (subject != nullptr)
    {
        subject->setName(newName);
    }
    sort();
}
void SubjectCollection::editSubjectTeacherFullName(const std::string& name, const std::string& newTeacherFullName)
{
    Subject* subject = getSubjectByName(name);
    if (subject != nullptr)
    {
        subject->setTeacherFullName(newTeacherFullName);
    }
}
void SubjectCollection::editSubjectRoomNumber(const std::string& name, unsigned newRoomNumber)
{
    Subject* subject = getSubjectByName(name);
    if (subject != nullptr)
    {
        subject->setRoomNumber(newRoomNumber);
    }
}
void SubjectCollection::deleteSubject(const std::string& name)
{
    for (unsigned i = 0; i < size; i++)
    {
        if (arr[i].getName() == name)
        {
            shiftLeft(i);
            size--;
            return;
        }
    }
}
void SubjectCollection::printAllSubjects() const
{
    if (size == 0)
    {
        std::cout << "No subjects added." << std::endl;
        return;
    }
    for (int i = 0; i < size; i++)
    {
        arr[i].printSubject();
    }
}
void SubjectCollection::sort()
{
    std::sort(arr, arr + size, [](const Subject& a, const Subject& b) 
    {
        return a.getName() < b.getName();
    });
}
bool SubjectCollection::doesNameExist(const std::string& name) const
{
    for (unsigned i = 0; i < size; i++)
    {
        if (name == arr[i].getName())
        {
            return true;
        }
    }
    return false;
}

void SubjectCollection::readFromBinaryFile(const char* fileName)
{
    std::ifstream ifs(fileName, std::ios::binary);
    if (!ifs.is_open())
    {
        throw std::runtime_error("Cannot open file for reading!");
    }
    free();
    ifs.read((char*)&nextId, sizeof(nextId));
    ifs.read((char*)&size, sizeof(size));
    capacity = calculateCapacity(size);
    arr = new Subject[capacity];
    for (unsigned i = 0; i < size; i++)
    {
        arr[i].readFromBinaryFile(ifs);
    }
    ifs.close();
}
void SubjectCollection::writeToBinaryFile(const char* fileName) const
{
    std::ofstream ofs(fileName, std::ios::binary);
    if (!ofs.is_open())
    {
        throw std::runtime_error("Cannot open file for writing!");
    }
    ofs.write((const char*)&nextId, sizeof(nextId));
    ofs.write((const char*)&size, sizeof(size));
    for (unsigned i = 0; i < size; ++i)
    {
        arr[i].writeToBinaryFile(ofs);
    }
    ofs.close();
}

unsigned SubjectCollection::getSize() const
{
    return size;
}
Subject* SubjectCollection::getSubjectByName(const std::string& name)
{
    for (unsigned i = 0; i < size; i++)
    {
        if (arr[i].getName() == name)
        {
            return &arr[i];
        }
    }
    return nullptr;
}
Subject* SubjectCollection::getSubjectById(unsigned id)
{
    for (unsigned i = 0; i < size; i++)
    {
        if (arr[i].getId() == id)
        {
            return &arr[i];
        }
    }
    return nullptr;
}
Subject& SubjectCollection::getSubjectAt(unsigned index)
{
    return arr[index];
}
