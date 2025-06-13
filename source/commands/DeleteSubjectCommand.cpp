#include "DeleteSubjectCommand.h"

DeleteSubjectCommand::DeleteSubjectCommand(SchoolClass& schoolClass)
 : schoolClass(schoolClass){}

void DeleteSubjectCommand::execute()
{
	if (schoolClass.getSubjects().getSize() == 0)
	{
		std::cout << "No subjects added." << std::endl;
		return;
	}

	std::string name = readName();
	schoolClass.getSubjects().deleteSubject(name);
	std::cout << "Subject deleted successfully!" << std::endl;
}


std::string DeleteSubjectCommand::readName()
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
				return name;
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
}

