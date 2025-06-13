#pragma once
#include <iostream>
#include "Utils.h"
#include "Command.h"
#include "SchoolClass.h"

using namespace Utils;

class TotalGradeCommand : public Command
{
public:
	TotalGradeCommand(SchoolClass& schoolClass);

	void execute() override;

private:
	unsigned readNumberInClass();

	SchoolClass& schoolClass;
};