#pragma once
#include <iostream>
#include <fstream>
#include <string>

class Subject
{
public:
	Subject();
	Subject(unsigned id, const std::string& name, const std::string& teacherFullName, unsigned roomNumber);

	void printSubject() const;

	void readFromBinaryFile(std::ifstream& ifs);
	void writeToBinaryFile(std::ofstream& ofs) const;

	unsigned getId() const;
	std::string getName() const;
	std::string getTeacherFullName() const;
	unsigned getRoomNumber() const;
	void setId(unsigned newId);
	void setName(const std::string& newName);
	void setTeacherFullName(const std::string& newTeacherFullName);
	void setRoomNumber(unsigned newRoomNumber);

private:
	unsigned id;
	std::string name;
	std::string teacherFullName;
	unsigned roomNumber;
};

