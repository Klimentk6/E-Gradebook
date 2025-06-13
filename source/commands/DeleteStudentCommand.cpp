#include "DeleteStudentCommand.h"

DeleteStudentCommand::DeleteStudentCommand(SchoolClass& schoolClass)
    : schoolClass(schoolClass) {}

void DeleteStudentCommand::execute()
{
    if (schoolClass.getStudents().getSize() == 0)
    {
        std::cout << "No students added." << std::endl;
        return;
    }
    unsigned numberInClass = readNumberInClass();
    schoolClass.getStudents().deleteStudent(numberInClass);
    std::cout << "Student deleted successfully!" << std::endl;
}

unsigned DeleteStudentCommand::readNumberInClass()
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
