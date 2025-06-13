#include "DeleteGradeCommand.h"

DeleteGradeCommand::DeleteGradeCommand(SchoolClass& schoolClass)
    : schoolClass(schoolClass) {}

void DeleteGradeCommand::execute()
{
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
    schoolClass.getGrades().deleteGrade(index);
    std::cout << "Grade deleted successfully!" << std::endl;
}

unsigned DeleteGradeCommand::readIndex()
{
    std::string input;
    unsigned index;
    while (true)
    {
        std::cout << "Enter index of the grade to delete (0 - "
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

