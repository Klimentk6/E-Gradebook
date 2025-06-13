#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Date.h"

class Grade
{
public:
	Grade();
	Grade(unsigned studentId, unsigned subjectId, double grade);

	void readFromBinaryFile(std::ifstream& ifs);
	void writeToBinaryFile(std::ofstream& ofs) const;

	unsigned getStudentId() const;
	unsigned getSubjectId() const;
	Date getDate() const;
	double getGrade() const;
	void setStudentId(unsigned newId);
	void setSubjectId(unsigned newId);
	void setDate(const Date& newDate);
	void setGrade(double newGrade);

private:
	unsigned studentId;
	unsigned subjectId;
	Date date;
	double grade;
};

