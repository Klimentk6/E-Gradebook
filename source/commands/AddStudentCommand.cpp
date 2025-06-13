#include "AddStudentCommand.h"

AddStudentCommand::AddStudentCommand(SchoolClass& schoolClass)
	:schoolClass(schoolClass) {}

void AddStudentCommand::execute()
{
	std::string fullName = readFullName();
	Date dateOfBirth = readDate();
	schoolClass.getStudents().addStudent(fullName, dateOfBirth);
	std::cout << "Student added successfully!" << std::endl;
}

std::string AddStudentCommand::readFullName()
{
	std::string fullName;
	while (true)
	{
		std::cout << "Enter full name: ";
		std::getline(std::cin, fullName);
		if (isValidFullName(fullName))
		{
			break;
		}
		std::cout << "Invalid input!" << std::endl;
	}
	return fullName;
}
Date AddStudentCommand::readDate()
{
	std::string dateOfBirthStr;
	while (true)
	{
		std::cout << "Enter date of birth: ";
		std::getline(std::cin, dateOfBirthStr);
		if (isValidDateString(dateOfBirthStr))
		{
			break;
		}
		std::cout << "Invalid input!" << std::endl;
	}
	std::vector<std::string> parts = split(dateOfBirthStr, '.');
	unsigned day = std::stoi(parts[0]);
	unsigned month = std::stoi(parts[1]);
	unsigned year = std::stoi(parts[2]);

	return Date(day, month, year);
}
