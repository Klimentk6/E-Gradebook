#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Utils.h"
#include "Command.h"
#include "SchoolClass.h"

using namespace Utils;

class EditSubjectCommand : public Command
{
public:
	EditSubjectCommand(SchoolClass& schoolClass);

	void execute() override;

private:
	std::string readOldName();
	std::string readName();
	std::string readTeacherFullName();
	unsigned readRoomNumber();

	SchoolClass& schoolClass;
};

