#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Utils.h"
#include "Date.h"
#include "Command.h"
#include "SchoolClass.h"

using namespace Utils;

class EditStudentCommand : public Command
{
public:
	EditStudentCommand(SchoolClass& schoolClass);

	void execute() override;

private:
	unsigned readNumberInClass();
	std::string readFullName();
	Date readDate();

	SchoolClass& schoolClass;
};

