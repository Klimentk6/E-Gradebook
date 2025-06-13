#pragma once
#include <iostream>
#include "Command.h"
#include "SchoolClass.h"

class StudentsCommand : public Command
{
public:
	StudentsCommand(SchoolClass& schoolClass);

	void execute() override;

private:
	SchoolClass& schoolClass;
};

