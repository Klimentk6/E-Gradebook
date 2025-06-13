#include "RemedialExamCommand.h"
#include <iostream>

RemedialExamCommand::RemedialExamCommand(SchoolClass& schoolClass)
    : schoolClass(schoolClass) {}

void RemedialExamCommand::execute()
{
    if (schoolClass.getStudents().getSize() == 0 ||
        schoolClass.getSubjects().getSize() == 0 ||
        schoolClass.getGrades().getSize() == 0)
    {
        std::cout << "Not enough data to evaluate remedial exams." << std::endl;
        return;
    }

    std::string subjectName = readSubjectName();
    unsigned subjectId = schoolClass.getSubjects().getSubjectByName(subjectName)->getId();

    bool found = false;

    for (unsigned i = 0; i < schoolClass.getStudents().getSize(); ++i)
    {
        const Student& student = schoolClass.getStudents().getStudentAt(i);
        unsigned studentId = student.getId();

        double sum = 0;
        unsigned count = 0;

        for (unsigned j = 0; j < schoolClass.getGrades().getSize(); ++j)
        {
            const Grade& grade = schoolClass.getGrades().getGradeAt(j);
            if (grade.getStudentId() == studentId && grade.getSubjectId() == subjectId)
            {
                sum += grade.getGrade();
                count++;
            }
        }

        if (count > 0)
        {
            double avg = sum / count;
            if (avg < 3.00)
            {
                found = true;
                std::cout << student.getFullName()
                    << " has an average of " << avg
                    << " in " << subjectName
                    << " and must take a remedial exam." << std::endl;
            }
        }
    }

    if (!found)
    {
        std::cout << "No students need to take a remedial exam in this subject." << std::endl;
    }
}

std::string RemedialExamCommand::readSubjectName()
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
