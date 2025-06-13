#pragma once
#include <iostream>
#include <string>
#include "Date.h"
#include "StudentCollection.h"
#include "SubjectCollection.h"
#include "GradeCollection.h"

class SchoolClass
{
public:
	SchoolClass();
	~SchoolClass();

	StudentCollection& getStudents();
	SubjectCollection& getSubjects();
	GradeCollection& getGrades();
	const StudentCollection& getStudents() const;
	const SubjectCollection& getSubjects() const;
	const GradeCollection& getGrades() const;

private:
	void readFromBinaryFile();
	void writeToBinaryFile() const;
	static const char* STUDENTS_FILE_NAME;
	static const char* SUBJECTS_FILE_NAME;
	static const char* GRADES_FILE_NAME;

	StudentCollection students;
	SubjectCollection subjects;
	GradeCollection grades;
};