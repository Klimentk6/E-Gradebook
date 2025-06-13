#include "Subject.h"

Subject::Subject()
{
    id = 0;
	name = "";
	teacherFullName = "";
	roomNumber = 0;
}
Subject::Subject(unsigned id, const std::string& name, const std::string& teacherFullName, unsigned roomNumber)
{
    this->id = id;
	this->name = name;
	this->teacherFullName = teacherFullName;
	this->roomNumber = roomNumber;
}

void Subject::printSubject() const
{
    std::cout << name
        << " | " << teacherFullName
        << " | " << roomNumber << std::endl;
}

void Subject::readFromBinaryFile(std::ifstream& ifs)
{
    ifs.read((char*)&id, sizeof(id));

    unsigned nameSize;
    ifs.read((char*)(&nameSize), sizeof(nameSize));
    name.resize(nameSize);
    ifs.read((char*)&name[0], nameSize * sizeof(char));

    unsigned teacherSize;
    ifs.read((char*)(&teacherSize), sizeof(teacherSize));
    teacherFullName.resize(teacherSize);
    ifs.read((char*)&teacherFullName[0], teacherSize * sizeof(char));

    ifs.read((char*)(&roomNumber), sizeof(roomNumber));
}
void Subject::writeToBinaryFile(std::ofstream& ofs) const 
{
    ofs.write((const char*)&id, sizeof(id));

    unsigned nameSize = name.size();
    ofs.write((const char*)(&nameSize), sizeof(nameSize));
    ofs.write(name.c_str(), nameSize * sizeof(char));

    unsigned teacherSize = teacherFullName.size();
    ofs.write((const char*)(&teacherSize), sizeof(teacherSize));
    ofs.write(teacherFullName.c_str(), sizeof(char) * teacherSize);

    ofs.write((const char*)(&roomNumber), sizeof(roomNumber));
}

unsigned Subject::getId() const
{
    return id;
}
std::string Subject::getName() const
{
	return name;
}
std::string Subject::getTeacherFullName() const
{
	return teacherFullName;
}
unsigned Subject::getRoomNumber() const
{
	return roomNumber;
}

void Subject::setId(unsigned newId)
{
    id = newId;
}
void Subject::setName(const std::string& newName)
{
    name = newName;
}
void Subject::setTeacherFullName(const std::string& newTeacherFullName)
{
    teacherFullName = newTeacherFullName;
}
void Subject::setRoomNumber(unsigned newRoomNumber)
{
    roomNumber = newRoomNumber;
}
