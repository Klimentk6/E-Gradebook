#include "StudentCollection.h"

StudentCollection::StudentCollection()
{
    nextId = 1;
    size = 0;
    capacity = MIN_CAPACITY;
    arr = new Student[capacity];
}
StudentCollection::StudentCollection(const StudentCollection& other)
{
    copyFrom(other);
}
StudentCollection::StudentCollection(StudentCollection&& other) noexcept
{
    moveFrom(std::move(other));
}
StudentCollection& StudentCollection::operator=(const StudentCollection& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}
StudentCollection& StudentCollection::operator=(StudentCollection&& other) noexcept
{
    if (this != &other)
    {
        free(); 
        moveFrom(std::move(other));
    }
    return *this;
}
StudentCollection::~StudentCollection()
{
    free();
}

void StudentCollection::copyFrom(const StudentCollection& other)
{
    nextId = other.nextId;
    size = other.size;
    capacity = other.capacity;
    arr = new Student[capacity];
    for (unsigned i = 0; i < size; i++)
    {
        arr[i] = other.arr[i];
    }
}
void StudentCollection::moveFrom(StudentCollection&& other)
{
    nextId = other.nextId;
    size = other.size;
    capacity = other.capacity;
    arr = other.arr;
    other.arr = nullptr;
    other.size = 0;
    other.capacity = 0;
}
void StudentCollection::free()
{
    delete[] arr;
    arr = nullptr;
}
void StudentCollection::resize(unsigned newCapacity)
{
    capacity = newCapacity;
    Student* temp = new Student[capacity];
    for (unsigned i = 0; i < size; i++)
    {
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
}
unsigned StudentCollection::calculateCapacity(unsigned requiredSize)
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
void StudentCollection::shiftLeft(int index)
{
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}

void StudentCollection::addStudent(const std::string& fullName, const Date& dateOfBirth)
{
    if (size == capacity)
    {
        resize(capacity * RESIZE_COEFF);
    }
    unsigned insertIndex = 0;
    while (insertIndex < size && arr[insertIndex].getFullName() < fullName)
    {
        insertIndex++;
    }
    for (unsigned i = size; i > insertIndex; --i)
    {
        arr[i] = arr[i - 1];
    }
    arr[insertIndex] = Student(nextId++, 0, fullName, dateOfBirth);
    size++;
    for (unsigned i = 0; i < size; ++i)
    {
        arr[i].setNumberInClass(i + 1);
    }
}
void StudentCollection::editStudentFullName(unsigned numberInClass, const std::string& fullName)
{
    Student* currentStudent = getStudentByNumberInClass(numberInClass);
    if (currentStudent != nullptr)
    {
        currentStudent->setFullName(fullName);
    }
    sort();
}
void StudentCollection::editStudentDateOfBirth(unsigned numberInClass, const Date& dateOfBirth)
{
    Student* currentStudent = getStudentByNumberInClass(numberInClass);
    if (currentStudent != nullptr)
    {
        currentStudent->setDateOfBirth(dateOfBirth);
    }
}
void StudentCollection::deleteStudent(unsigned numberInClass)
{
    if (numberInClass == 0 || numberInClass > size)
        return;

    for (int i = 0; i < size; i++)
    {
        if (arr[i].getNumberInClass() == numberInClass)
        {
            shiftLeft(i);
            size--;
            for (unsigned j = 0; j < size; j++)
            {
                arr[j].setNumberInClass(j + 1);
            }
            break;
        }
    }
}
void StudentCollection::printAllStudents() const
{
    if (size == 0)
    {
        std::cout << "No students added." << std::endl;
        return;
    }
    for (unsigned i = 0; i < size; i++)
    {
        arr[i].printStudent();
    }
}
void StudentCollection::printBirthdayStudents() const
{
    if (size == 0)
    {
        std::cout << "No students added." << std::endl;
        return;
    }
    bool found = false;
    for (unsigned i = 0; i < size; i++)
    {
        if(arr[i].getDateOfBirth().isTodayBirthday())
        {
            found = true;
            arr[i].printStudent();
        }
    }
    if (!found)
    {
        std::cout << "No birthday students." << std::endl;
    }
}
void StudentCollection::sort()
{
    std::sort(arr, arr + size, [](const Student& a, const Student& b) 
    {
        return a.getFullName() < b.getFullName();
    });

    for (unsigned i = 0; i < size; i++)
    {
        arr[i].setNumberInClass(i + 1);
    }
}

void StudentCollection::readFromBinaryFile(const char* fileName)
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
    arr = new Student[capacity];
    for (unsigned i = 0; i < size; i++)
    {
        arr[i].readFromBinaryFile(ifs);
    }
    ifs.close();
}
void StudentCollection::writeToBinaryFile(const char* fileName) const
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

unsigned StudentCollection::getSize() const
{
    return size;
}

Student* StudentCollection::getStudentByNumberInClass(unsigned numberInClass)
{
    for (unsigned i = 0; i < size; i++)
    {
        if (numberInClass == arr[i].getNumberInClass())
        {
            return &arr[i];
        }
    }
    return nullptr;
}
Student* StudentCollection::getStudentById(unsigned id)
{
    for (unsigned i = 0; i < size; i++)
    {
        if (id == arr[i].getId())
        {
            return &arr[i];
        }
    }
    return nullptr;
}

const Student& StudentCollection::getStudentAt(unsigned index) const
{
    return arr[index];
}

