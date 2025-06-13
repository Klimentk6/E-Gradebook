#include "GradeCollection.h"

GradeCollection::GradeCollection()
{
	size = 0;
	capacity = MIN_CAPACITY;
	arr = new Grade[MIN_CAPACITY];
}
GradeCollection::GradeCollection(const GradeCollection& other) 
{
	copyFrom(other);
}
GradeCollection::GradeCollection(GradeCollection&& other) noexcept
{
	moveFrom(std::move(other));
}
GradeCollection& GradeCollection::operator=(const GradeCollection& other) 
{
	if (this != &other) 
	{
		free();
		copyFrom(other);
	}
	return *this;
}
GradeCollection& GradeCollection::operator=(GradeCollection&& other) noexcept 
{
	if (this != &other) 
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}
GradeCollection::~GradeCollection() 
{
	free();
}

void GradeCollection::copyFrom(const GradeCollection& other) 
{
	size = other.size;
	capacity = other.capacity;
	arr = new Grade[other.capacity];
	for (unsigned i = 0; i < other.size; i++)
	{
		arr[i] = other.arr[i];
	}
}
void GradeCollection::moveFrom(GradeCollection&& other)
{
	arr = other.arr;
	size = other.size;
	capacity = other.capacity;
	other.arr = nullptr;
	other.size = 0;
	other.capacity = 0;
}
void GradeCollection::free() 
{
	delete[] arr;
	arr = nullptr;
}
unsigned GradeCollection::calculateCapacity(unsigned requiredSize)
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
void GradeCollection::resize(unsigned newCapacity) 
{
	capacity = newCapacity;
	Grade* temp = new Grade[capacity];
	for (unsigned i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = temp;

}
Grade* GradeCollection::getGrade(unsigned studentId, unsigned subjectId) 
{
	for (unsigned i = 0; i < size; i++) 
	{
		if (arr[i].getStudentId() == studentId && arr[i].getSubjectId() == subjectId)
		{
			return &arr[i];
		}
	}
	return nullptr;
}
void GradeCollection::shiftLeft(int index) 
{
	for (unsigned i = index; i + 1 < size; i++)
	{
		arr[i] = arr[i + 1];
	}
	--size;
}

void GradeCollection::addGrade(const Grade& grade)
{
	if (size == capacity)
	{
		resize(capacity * RESIZE_COEFF);
	}
	arr[size] = grade;
	size++;
}
void GradeCollection::editGrade(unsigned index, const Grade& newGrade) 
{
	arr[index] = newGrade;
}
void GradeCollection::deleteGrade(unsigned index)
{
	shiftLeft(index);
}
void GradeCollection::readFromBinaryFile(const char* fileName)
{
	std::ifstream ifs(fileName, std::ios::binary);
	if (!ifs.is_open())
	{
		throw std::runtime_error("Cannot open file for reading!");
	}
	free();
	ifs.read((char*)&size, sizeof(size));
	capacity = calculateCapacity(size);
	arr = new Grade[capacity];
	for (unsigned i = 0; i < size; i++)
	{
		arr[i].readFromBinaryFile(ifs);
	}
	ifs.close();
}
void GradeCollection::writeToBinaryFile(const char* fileName) const
{
	std::ofstream ofs(fileName, std::ios::binary);
	if (!ofs.is_open())
	{
		throw std::runtime_error("Cannot open file for writing!");
	}
	ofs.write((const char*)&size, sizeof(size));
	for (unsigned i = 0; i < size; ++i)
	{
		arr[i].writeToBinaryFile(ofs);
	}
	ofs.close();
}

Grade& GradeCollection::getGradeAt(unsigned index)
{
	return arr[index];
}
const Grade& GradeCollection::getGradeAt(unsigned index) const
{
	return arr[index];
}
unsigned GradeCollection::getSize() const
{
	return size;
}
