#include "AddSubjectCommand.h"

AddSubjectCommand::AddSubjectCommand(SchoolClass& schoolClass)
	:schoolClass(schoolClass) {}

void AddSubjectCommand::execute()
{
	std::string name;
	while (true)
	{
		name = readName();
		if (!schoolClass.getSubjects().doesNameExist(name))
		{
			break;
		}
		std::cout << "Invalid name! This name already exists." << std::endl;
	}
	std::string teacherFullName = readTeacherFullName();
	unsigned roomNumber = readRoomNumber();
	schoolClass.getSubjects().addSubject(name, teacherFullName, roomNumber);
	std::cout << "Subject added successfully!" << std::endl;
}

std::string AddSubjectCommand::readName()
{
	std::string name;
	while (true)
	{
		std::cout << "Enter subject name: ";
		std::getline(std::cin, name);
		if (!name.empty() && name.find_first_not_of(' ') != std::string::npos)
		{
			break;
		}
		std::cout << "Invalid name!" << std::endl;
	}
	return name;
}
std::string AddSubjectCommand::readTeacherFullName()
{
	std::string fullName;
	while (true)
	{
		std::cout << "Enter teacher full name: ";
		std::getline(std::cin, fullName);
		if (isValidFullName(fullName))
		{
			break;
		}
		std::cout << "Invalid teacher full name!" << std::endl;
	}
	return fullName;
}
unsigned AddSubjectCommand::readRoomNumber()
{
	std::string roomNumberStr;
	unsigned roomNumber;
	while (true)
	{
		std::cout << "Enter room number: ";
		std::getline(std::cin, roomNumberStr);
		if (isStringUnsigned(roomNumberStr))
		{
			try
			{
				roomNumber = std::stoul(roomNumberStr);
				if (roomNumber > 0)
				{
					break;
				}
			}
			catch (...) {}
		}

		std::cout << "Invalid input! Pleas enter a positive number." << std::endl;
	}
	return roomNumber;
}