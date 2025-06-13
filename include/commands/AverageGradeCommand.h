#pragma once
#include <iostream>
#include "Utils.h"
#include "Command.h"
#include "SchoolClass.h"

using namespace Utils;

class AverageGradeCommand : public Command
{
public:
	AverageGradeCommand(SchoolClass& schoolClass);

	void execute() override;

private:
	unsigned readNumberInClass();
	std::string readSubjectName();

	SchoolClass& schoolClass;
};

