#include "Grade.h"

Grade::Grade() : studentId(0), subjectId(0), grade(0.0), date() {}
Grade::Grade(unsigned studentId, unsigned subjectId, double grade)
    : studentId(studentId), subjectId(subjectId), grade(grade), date() 
{
    date.setToToday();
}

void Grade::readFromBinaryFile(std::ifstream& ifs) 
{
    ifs.read((char*)(&studentId), sizeof(studentId));
    ifs.read((char*)(&subjectId), sizeof(subjectId));
    ifs.read((char*)(&grade), sizeof(grade));
    date.readFromBinaryFile(ifs);
}
void Grade::writeToBinaryFile(std::ofstream& ofs) const 
{
    ofs.write((const char*)(&studentId), sizeof(studentId));
    ofs.write((const char*)(&subjectId), sizeof(subjectId));
    ofs.write((const char*)(&grade), sizeof(grade));
    date.writeToBinaryFile(ofs);
}

unsigned Grade::getStudentId() const 
{
    return studentId;
}
unsigned Grade::getSubjectId() const 
{
    return subjectId;
}
Date Grade::getDate() const 
{
    return date;
}
double Grade::getGrade() const 
{
    return grade;
}
void Grade::setStudentId(unsigned newId) 
{
    studentId = newId;
}
void Grade::setSubjectId(unsigned newId) 
{
    subjectId = newId;
}
void Grade::setDate(const Date& newDate) 
{
    date = newDate;
}
void Grade::setGrade(double newGrade) 
{
    grade = newGrade;
}
