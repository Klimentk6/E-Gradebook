#include "SchoolClass.h"
const char* SchoolClass::STUDENTS_FILE_NAME = "studentsData.bin";
const char* SchoolClass::SUBJECTS_FILE_NAME = "subjectsData.bin";
const char* SchoolClass::GRADES_FILE_NAME = "gradesData.bin";

SchoolClass::SchoolClass() : students()
{
	try
	{
		readFromBinaryFile();
	}
	catch (const std::runtime_error&) {}
}
SchoolClass::~SchoolClass()
{
	writeToBinaryFile();
}

StudentCollection& SchoolClass::getStudents()
{
	return students;
}
SubjectCollection& SchoolClass::getSubjects()
{
	return subjects;
}
GradeCollection& SchoolClass::getGrades()
{
	return grades;
}
const StudentCollection& SchoolClass::getStudents() const
{
	return students;
}
const SubjectCollection& SchoolClass::getSubjects() const
{
	return subjects;
}
const GradeCollection& SchoolClass::getGrades() const
{
	return grades;
}

void SchoolClass::readFromBinaryFile()
{
	students.readFromBinaryFile(STUDENTS_FILE_NAME);
	subjects.readFromBinaryFile(SUBJECTS_FILE_NAME);
	grades.readFromBinaryFile(GRADES_FILE_NAME);
}
void SchoolClass::writeToBinaryFile() const
{
	students.writeToBinaryFile(STUDENTS_FILE_NAME);
	subjects.writeToBinaryFile(SUBJECTS_FILE_NAME);
	grades.writeToBinaryFile(GRADES_FILE_NAME);
}
