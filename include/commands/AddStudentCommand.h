#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Utils.h"
#include "Date.h"
#include "Command.h"
#include "SchoolClass.h"

using namespace Utils;

class AddStudentCommand : public Command
{
public:
	AddStudentCommand(SchoolClass& schoolClass);

	void execute() override;

private:
	std::string readFullName();
	Date readDate();

	SchoolClass& schoolClass;
};

