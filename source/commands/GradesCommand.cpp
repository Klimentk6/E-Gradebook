#include "GradesCommand.h"

GradesCommand::GradesCommand(SchoolClass& schoolClass)
	: schoolClass(schoolClass) {}

void GradesCommand::execute()
{
	if (schoolClass.getGrades().getSize() == 0)
	{
		std::cout << "No grades added." << std::endl;
		return;
	}
	for (unsigned i = 0; i < schoolClass.getGrades().getSize(); i++)
	{
		Grade& grade = schoolClass.getGrades().getGradeAt(i);
		Student* student = schoolClass.getStudents().getStudentById(grade.getStudentId());
		Subject* subject = schoolClass.getSubjects().getSubjectById(grade.getSubjectId());
		if (student && subject)
		{
			std::cout << student->getFullName() << " | " << subject->getName() << " | " << grade.getDate() << " | " << grade.getGrade() << std::endl;
		}
	}
}

