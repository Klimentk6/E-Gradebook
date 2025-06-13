#include "EditSubjectCommand.h"

EditSubjectCommand::EditSubjectCommand(SchoolClass& schoolClass)
	: schoolClass(schoolClass) {}

void EditSubjectCommand::execute()
{
	if (schoolClass.getSubjects().getSize() == 0)
	{
		std::cout << "No subjects added." << std::endl;
		return;
	}
	std::string oldName = readOldName();
	std::string name = readName();
	std::string teacherFullName = readTeacherFullName();
	unsigned roomNumber = readRoomNumber();
	schoolClass.getSubjects().editSubjectTeacherFullName(oldName, teacherFullName);
	schoolClass.getSubjects().editSubjectRoomNumber(oldName, roomNumber);
	schoolClass.getSubjects().editSubjectName(oldName, name);
	std::cout << "Subject edited successfully!" << std::endl;
}

std::string EditSubjectCommand::readOldName()
{
	std::string name;
	while (true)
	{
		std::cout << "Enter subject name: ";
		std::getline(std::cin, name);
		if (!name.empty() && name.find_first_not_of(' ') != std::string::npos)
		{
			if (schoolClass.getSubjects().doesNameExist(name))
			{
				break;
			}
			else
			{
				std::cout << "Invalid subject! This subject does not exist." << std::endl;
			}
		}
		else
		{
			std::cout << "Invalid name!" << std::endl;
		}
	}
	return name;
}
std::string EditSubjectCommand::readName()
{
	std::string name;
	while (true)
	{
		std::cout << "Enter new subject name: ";
		std::getline(std::cin, name);
		if (!name.empty() && name.find_first_not_of(' ') != std::string::npos)
		{
			if (!schoolClass.getSubjects().doesNameExist(name))
			{
				break;
			}
			else
			{
				std::cout << "Invalid name! This name already exists." << std::endl;
			}
		}
		else
		{
			std::cout << "Invalid name!" << std::endl;
		}
	}
	return name;
}
std::string EditSubjectCommand::readTeacherFullName()
{
	std::string fullName;
	while (true)
	{
		std::cout << "Enter new teacher full name: ";
		std::getline(std::cin, fullName);
		if (isValidFullName(fullName))
		{
			break;
		}
		std::cout << "Invalid teacher full name!" << std::endl;
	}
	return fullName;
}
unsigned EditSubjectCommand::readRoomNumber()
{
	std::string roomNumberStr;
	unsigned roomNumber;
	while (true)
	{
		std::cout << "Enter new room number: ";
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

		std::cout << "Invalid input! Please enter a positive number." << std::endl;
	}
	return roomNumber;
}
