#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Grade.h"
#include "Date.h"

class GradeCollection
{
public:
	GradeCollection();
	GradeCollection(const GradeCollection& other);
	GradeCollection(GradeCollection&& other) noexcept;
	GradeCollection& operator=(const GradeCollection& other);
	GradeCollection& operator=(GradeCollection&& other) noexcept;
	~GradeCollection();

	void addGrade(const Grade& newGrade);
	void editGrade(unsigned index, const Grade& newGrade);
	void deleteGrade(unsigned index);

	void readFromBinaryFile(const char* fileName);
	void writeToBinaryFile(const char* fileName) const;

	Grade& getGradeAt(unsigned index);
	const Grade& getGradeAt(unsigned index) const;
	unsigned getSize() const;

private:
	static const unsigned MIN_CAPACITY = 16;
	static const unsigned RESIZE_COEFF = 2;
	void copyFrom(const GradeCollection& other);
	void moveFrom(GradeCollection&& other);
	void free();
	void resize(unsigned newCapacity);
	static unsigned calculateCapacity(unsigned requiredSize);
	void shiftLeft(int index);
	Grade* getGrade(unsigned studentId, unsigned subjectId);

	Grade* arr;
	unsigned size;
	unsigned capacity;
};

