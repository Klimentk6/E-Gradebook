#include "EditGradeCommand.h"

EditGradeCommand::EditGradeCommand(SchoolClass& schoolClass)
    : schoolClass(schoolClass) {}

void EditGradeCommand::execute()
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
    if (schoolClass.getGrades().getSize() == 0)
    {
        std::cout << "No grades added." << std::endl;
        return;
    }
    for (unsigned i = 0; i < schoolClass.getGrades().getSize(); ++i)
    {
        const Grade& grade = schoolClass.getGrades().getGradeAt(i);
        Student* student = schoolClass.getStudents().getStudentById(grade.getStudentId());
        Subject* subject = schoolClass.getSubjects().getSubjectById(grade.getSubjectId());

        if (student && subject)
        {
            std::cout << "[" << i << "] "
                << student->getFullName() << " | "
                << subject->getName() << " | "
                << grade.getGrade() << std::endl;
        }
    }
    unsigned index = readIndex();
    Grade& grade = schoolClass.getGrades().getGradeAt(index);
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
    unsigned studentId = schoolClass.getStudents()
        .getStudentByNumberInClass(readNumberInClass())
        ->getId();

    unsigned subjectId = schoolClass.getSubjects()
        .getSubjectByName(readSubjectName())
        ->getId();

    double newGradeValue = readGrade();
    grade.setStudentId(studentId);
    grade.setSubjectId(subjectId);
    grade.setGrade(newGradeValue);
    std::cout << "Grade edited successfully!" << std::endl;
}


unsigned EditGradeCommand::readIndex()
{
    std::string input;
    unsigned index;
    while (true)
    {
        std::cout << "Enter index of the grade to edit (0 - "
            << schoolClass.getGrades().getSize() - 1 << "): ";
        std::getline(std::cin, input);
        if (isStringUnsigned(input))
        {
            try
            {
                index = std::stoul(input);
                if (index < schoolClass.getGrades().getSize())
                {
                    return index;
                }
            }
            catch (...) {}
        }
        std::cout << "Invalid input! Please enter a valid index." << std::endl;
    }
}
unsigned EditGradeCommand::readNumberInClass()
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
std::string EditGradeCommand::readSubjectName()
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
double EditGradeCommand::readGrade()
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