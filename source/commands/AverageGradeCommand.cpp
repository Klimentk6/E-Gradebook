#include "AverageGradeCommand.h"

AverageGradeCommand::AverageGradeCommand(SchoolClass& schoolClass)
	: schoolClass(schoolClass) {}

void AverageGradeCommand::execute()
{
    if (schoolClass.getGrades().getSize() == 0)
    {
        std::cout << "No grades added." << std::endl;
        return;
    }
    unsigned studentId = schoolClass.getStudents()
        .getStudentByNumberInClass(readNumberInClass())
        ->getId();
    unsigned subjectId = schoolClass.getSubjects()
        .getSubjectByName(readSubjectName())
        ->getId();
    unsigned count = 0;
    double sum = 0;
    for (unsigned i = 0; i < schoolClass.getGrades().getSize(); i++)
    {
        const Grade& grade = schoolClass.getGrades().getGradeAt(i);
        if (grade.getStudentId() == studentId && grade.getSubjectId() == subjectId)
        {
            sum += grade.getGrade();
            count++;
        }
    }
    if (count == 0)
    {
        std::cout << "This student has no grades in the selected subject." << std::endl;
    }
    else
    {
        double average = sum / count;
        std::cout << schoolClass.getStudents().getStudentById(studentId)->getFullName()
            << " | " << schoolClass.getSubjects().getSubjectById(subjectId)->getName()
            << " | Average grade: " << average << std::endl;
    }
}

unsigned AverageGradeCommand::readNumberInClass()
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
std::string AverageGradeCommand::readSubjectName()
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
