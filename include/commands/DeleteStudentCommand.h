#pragma once
#include <iostream>
#include "Utils.h"
#include "Command.h"
#include "SchoolClass.h"

using namespace Utils;

class DeleteStudentCommand : public Command
{
public:
	DeleteStudentCommand(SchoolClass& schoolClass);

	void execute() override;

private:
	unsigned readNumberInClass();

	SchoolClass& schoolClass;
};

