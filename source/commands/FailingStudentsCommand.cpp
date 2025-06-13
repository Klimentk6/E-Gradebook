#include "FailingStudentsCommand.h"
#include <iostream>
#include <vector>

FailingStudentsCommand::FailingStudentsCommand(SchoolClass& schoolClass)
    : schoolClass(schoolClass) {}

void FailingStudentsCommand::execute()
{
    if (schoolClass.getStudents().getSize() == 0 ||
        schoolClass.getSubjects().getSize() == 0 ||
        schoolClass.getGrades().getSize() == 0)
    {
        std::cout << "Not enough data to evaluate failing students." << std::endl;
        return;
    }

    bool foundFailingStudent = false;  

    for (unsigned i = 0; i < schoolClass.getStudents().getSize(); ++i)
    {
        const Student& student = schoolClass.getStudents().getStudentAt(i);
        unsigned studentId = student.getId();
        unsigned subjectCount = schoolClass.getSubjects().getSize();
        std::vector<bool> hasFailingGrade(subjectCount, false);
        for (unsigned j = 0; j < schoolClass.getGrades().getSize(); ++j)
        {
            const Grade& grade = schoolClass.getGrades().getGradeAt(j);
            if (grade.getStudentId() == studentId && grade.getGrade() < 3.00)
            {
                unsigned subjectId = grade.getSubjectId();

                for (unsigned k = 0; k < subjectCount; ++k)
                {
                    if (schoolClass.getSubjects().getSubjectAt(k).getId() == subjectId)
                    {
                        hasFailingGrade[k] = true;
                        break;
                    }
                }
            }
        }

        unsigned failingSubjects = 0;
        for (bool fail : hasFailingGrade)
        {
            if (fail) failingSubjects++;
        }

        if (failingSubjects >= 3)
        {
            std::cout << student.getFullName() << " is failing in " << failingSubjects << " subjects." << std::endl;
            foundFailingStudent = true;
        }
    }

    if (!foundFailingStudent)
    {
        std::cout << "No students are failing in 3 or more subjects." << std::endl;
    }
}

