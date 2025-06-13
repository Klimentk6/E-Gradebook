#include "EditStudentCommand.h"

EditStudentCommand::EditStudentCommand(SchoolClass& schoolClass)
    :schoolClass(schoolClass) {}

void EditStudentCommand::execute()
{
	if (schoolClass.getStudents().getSize() == 0)
	{
		std::cout << "No students added." << std::endl;
		return;
	}
	unsigned numberInClass = readNumberInClass();
    std::string fullName = readFullName();
	schoolClass.getStudents().editStudentFullName(numberInClass, fullName);
    Date dateOfBirth = readDate();
	schoolClass.getStudents().editStudentDateOfBirth(numberInClass, dateOfBirth);
    std::cout << "Student edited successfully!" << std::endl;
}

unsigned EditStudentCommand::readNumberInClass()
{
	std::string numberInClassStr;
	unsigned numberInClass;
	while (true)
	{
		std::cout << "Enter number in class (1-" << schoolClass.getStudents().getSize() << "): ";
		std::getline(std::cin, numberInClassStr);

		if (isStringUnsigned(numberInClassStr))
		{
			try
			{
				numberInClass = std::stoul(numberInClassStr);
				if (numberInClass >= 1 && numberInClass <= schoolClass.getStudents().getSize())
				{
					break;
				}
			}
			catch (...) {}
		}

		std::cout << "Invalid input! Please enter a number between 1 and "
			<< schoolClass.getStudents().getSize() << std::endl;
	}
	return numberInClass;
}
std::string EditStudentCommand::readFullName()
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
Date EditStudentCommand::readDate()
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
