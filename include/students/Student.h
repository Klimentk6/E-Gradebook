#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Date.h"

class Student
{
public:
	Student();
	Student(unsigned id, unsigned numberInClass, const std::string& fullname, const Date& dateOfBirth);

	void printStudent() const;

	void readFromBinaryFile(std::ifstream& ifs);
	void writeToBinaryFile(std::ofstream& ofs) const;

	unsigned getId() const;
	unsigned getNumberInClass() const;
	std::string getFullName() const;
	Date getDateOfBirth() const;
	void setId(unsigned newId);
	void setFullName(const std::string& newFullname);
	void setDateOfBirth(const Date& newDateOfBirth);
	void setNumberInClass(unsigned newNumberInClass);

private:
	unsigned id;
	unsigned numberInClass;
	std::string fullName;
	Date dateOfBirth;
};


