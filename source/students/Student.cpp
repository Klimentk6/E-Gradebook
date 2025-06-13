#include "Student.h"

Student::Student() : dateOfBirth()
{
	id = 0;
	numberInClass = 0;
	fullName = "";
}
Student::Student(unsigned id, unsigned numberInClass, const std::string& fullname, const Date& dateOfBirth)
{
	this->id = id;
	this->numberInClass = numberInClass;
	this->fullName = fullname;
	this->dateOfBirth = dateOfBirth;
}

void Student::printStudent() const
{
	std::cout << "#" << numberInClass << " | " << fullName << " | ";
	dateOfBirth.printDate();
}

void Student::readFromBinaryFile(std::ifstream& ifs)
{
	ifs.read((char*)&id, sizeof(id));

	ifs.read((char*)&numberInClass, sizeof(numberInClass));

	unsigned size;
	ifs.read((char*)&size, sizeof(size));
	fullName.resize(size);
	ifs.read((char*)&fullName[0], size * sizeof(char));

	dateOfBirth.readFromBinaryFile(ifs);
}
void Student::writeToBinaryFile(std::ofstream& ofs) const
{
	ofs.write((const char*)&id, sizeof(id));

	ofs.write((const char*)&numberInClass, sizeof(numberInClass));

	unsigned size = fullName.size();
	ofs.write((const char*)&size, sizeof(size));
	ofs.write((const char*)fullName.c_str(), size * sizeof(char));

	dateOfBirth.writeToBinaryFile(ofs);
}

unsigned Student::getId() const
{
	return id;
}
unsigned Student::getNumberInClass() const
{
	return numberInClass;
}
std::string Student::getFullName() const
{
	return fullName;
}
Date Student::getDateOfBirth() const
{
	return dateOfBirth;
}
void Student::setId(unsigned newId)
{
	id = newId;
}
void Student::setNumberInClass(unsigned newNumberInClass)
{
	numberInClass = newNumberInClass;
}
void Student::setFullName(const std::string& newFullname)
{
	fullName = newFullname;
}
void Student::setDateOfBirth(const Date& newDateOfBirth)
{
	dateOfBirth = newDateOfBirth;
}
