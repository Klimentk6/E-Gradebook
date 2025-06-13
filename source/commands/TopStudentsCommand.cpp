#include "TopStudentsCommand.h"

TopStudentsCommand::TopStudentsCommand(SchoolClass& schoolClass)
    : schoolClass(schoolClass) {}

void TopStudentsCommand::execute()
{
    const StudentCollection& students = schoolClass.getStudents();
    const GradeCollection& grades = schoolClass.getGrades();
    unsigned studentCount = students.getSize();

    bool found = false;

    for (unsigned i = 0; i < studentCount; ++i)
    {
        const Student& student = students.getStudentAt(i);
        unsigned studentId = student.getId();

        double total = 0;
        unsigned count = 0;

        for (unsigned j = 0; j < grades.getSize(); ++j)
        {
            const Grade& grade = grades.getGradeAt(j);
            if (grade.getStudentId() == studentId)
            {
                total += grade.getGrade();
                count++;
            }
        }

        if (count == 0)
            continue;

        double average = total / count;
        if (average >= 5.5)
        {
            std::cout << student.getFullName()
                << " | Average Grade: " << average << std::endl;
            found = true;
        }
    }

    if (!found)
    {
        std::cout << "No top students found." << std::endl;
    }
}

