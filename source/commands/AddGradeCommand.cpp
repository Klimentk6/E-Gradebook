#include "AddGradeCommand.h"

AddGradeCommand::AddGradeCommand(SchoolClass& schoolClass)
    :schoolClass(schoolClass) {}

void AddGradeCommand::execute()
{
    if (schoolClass.getStudents().getSize() == 0)
    {
        std::cout << "No students added." << std::endl;
        return;
    }
    if (schoolClass.getSubjects().getSize() == 0)
    {
        std::cout << "No subjects added." << std::endl;
        return;
    }
    unsigned studentId = schoolClass.getStudents().getStudentByNumberInClass(readNumberInClass())->getId();
    unsigned subjectId = schoolClass.getSubjects().getSubjectByName(readSubjectName())->getId();
    double grade = readGrade();
    Grade newGrade(studentId, subjectId, grade);
    schoolClass.getGrades().addGrade(newGrade);
    std::cout << "Grade added successfully!" << std::endl;
}

unsigned AddGradeCommand::readNumberInClass()
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
std::string AddGradeCommand::readSubjectName()
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
double AddGradeCommand::readGrade()
{
    std::string gradeStr;
    double grade;

    while (true)
    {
        std::cout << "Enter grade (2.00 - 6.00): ";
        std::getline(std::cin, gradeStr);

        try
        {
            grade = std::stod(gradeStr);
            if (grade >= 2.00 && grade <= 6.00)
            {
                return grade;
            }
        }
        catch (...) {}

        std::cout << "Invalid grade! Please enter a number between 2.00 and 6.00." << std::endl;
    }
}

