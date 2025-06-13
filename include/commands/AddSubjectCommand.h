#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Utils.h"
#include "Command.h"
#include "SchoolClass.h"

using namespace Utils;

class AddSubjectCommand : public Command
{
public:
	AddSubjectCommand(SchoolClass& schoolClass);

	void execute() override;

private:
	std::string readName();
	std::string readTeacherFullName();
	unsigned readRoomNumber();

	SchoolClass& schoolClass;
};

