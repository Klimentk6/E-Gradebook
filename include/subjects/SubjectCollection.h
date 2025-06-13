#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
#include "Subject.h"

class SubjectCollection
{
public:
    SubjectCollection();
    SubjectCollection(const SubjectCollection& other);
    SubjectCollection(SubjectCollection&& other) noexcept;
    SubjectCollection& operator=(const SubjectCollection& other);
    SubjectCollection& operator=(SubjectCollection&& other) noexcept;
    ~SubjectCollection();

    void addSubject(const std::string& name, const std::string& teacherFullName, unsigned roomNumber);
    void editSubjectName(const std::string& oldName, const std::string& newName);
    void editSubjectTeacherFullName(const std::string& name, const std::string& newTeacherFullName);
    void editSubjectRoomNumber(const std::string& name, unsigned newRoomNumber);
    void deleteSubject(const std::string& name);
    void printAllSubjects() const;
    void sort();
    bool doesNameExist(const std::string& name) const;

    void readFromBinaryFile(const char* fileName);
    void writeToBinaryFile(const char* fileName) const;

    unsigned getSize() const;
    Subject* getSubjectByName(const std::string& name);
    Subject* getSubjectById(unsigned id);
    Subject& getSubjectAt(unsigned index);

private:
    static const unsigned MIN_CAPACITY = 16;
    static const unsigned RESIZE_COEFF = 2;
    void copyFrom(const SubjectCollection& other);
    void moveFrom(SubjectCollection&& other);
    void free();
    void resize(unsigned newCapacity);
    static unsigned calculateCapacity(unsigned requiredSize);
    void shiftLeft(int index);

    Subject* arr;
    unsigned size;
    unsigned capacity;
    unsigned nextId;
};


