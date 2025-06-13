#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Utils.h"
#include "Date.h"
#include "Command.h"
#include "Grade.h"
#include "SchoolClass.h"

using namespace Utils;

class AddGradeCommand : public Command
{
public:
	AddGradeCommand(SchoolClass& schoolClass);

	void execute() override;

private:
	unsigned readNumberInClass();
	std::string readSubjectName();
	double readGrade();

	SchoolClass& schoolClass;
};

