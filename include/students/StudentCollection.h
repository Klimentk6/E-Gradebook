#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Student.h"
#include "Date.h"

class StudentCollection
{
public:
	StudentCollection();
	StudentCollection(const StudentCollection& other);
	StudentCollection(StudentCollection&& other) noexcept;
	StudentCollection& operator=(const StudentCollection& other);
	StudentCollection& operator=(StudentCollection&& other) noexcept;
	~StudentCollection();

	void addStudent(const std::string& fullName, const Date& dateOfBirth);
	void editStudentFullName(unsigned numberInClass, const std::string& fullName);
	void editStudentDateOfBirth(unsigned numberInClass, const Date& dateOfBirth);
	void deleteStudent(unsigned numberInClass);
	void printAllStudents() const;
	void printBirthdayStudents() const;
	void sort();

	void readFromBinaryFile(const char* fileName);
	void writeToBinaryFile(const char* fileName) const;

	unsigned getSize() const;
	Student* getStudentByNumberInClass(unsigned numberInClass);
	Student* getStudentById(unsigned id);
	const Student& getStudentAt(unsigned index) const;

private:
	static const unsigned MIN_CAPACITY = 16;
	static const unsigned RESIZE_COEFF = 2;
	void copyFrom(const StudentCollection& other);
	void moveFrom(StudentCollection&& other);
	void free();
	void resize(unsigned newCapacity);
	static unsigned calculateCapacity(unsigned requiredSize);
	void shiftLeft(int index);

	Student* arr;
	unsigned size;
	unsigned capacity;
	unsigned nextId;
};

