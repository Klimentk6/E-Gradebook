#pragma once
#include <iostream>
#include "Utils.h"
#include "Command.h"
#include "SchoolClass.h"

using namespace Utils;

class EditGradeCommand : public Command
{
public:
	EditGradeCommand(SchoolClass& schoolClass);

	void execute() override;

private:
	unsigned readIndex();
	unsigned readNumberInClass();
	std::string readSubjectName();
	double readGrade();


	SchoolClass& schoolClass;
};

