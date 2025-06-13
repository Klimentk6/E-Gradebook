#include "TotalGradeCommand.h"

TotalGradeCommand::TotalGradeCommand(SchoolClass& schoolClass)
	: schoolClass(schoolClass) {}

void TotalGradeCommand::execute()
{
    if (schoolClass.getGrades().getSize() == 0)
    {
        std::cout << "No grades added." << std::endl;
        return;
    }
    unsigned studentId = schoolClass.getStudents()
        .getStudentByNumberInClass(readNumberInClass())
        ->getId();

    double sum = 0;
    unsigned count = 0;

    for (unsigned i = 0; i < schoolClass.getGrades().getSize(); ++i)
    {
        const Grade& grade = schoolClass.getGrades().getGradeAt(i);
        if (grade.getStudentId() == studentId)
        {
            sum += grade.getGrade();
            ++count;
        }
    }

    if (count == 0)
    {
        std::cout << "This student has no grades." << std::endl;
    }
    else
    {
        double average = sum / count;
        std::cout << schoolClass.getStudents().getStudentById(studentId)->getFullName()
            << " | Average grade: " << average << std::endl;
    }
}


unsigned TotalGradeCommand::readNumberInClass()
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
