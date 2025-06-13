#pragma once
#include <iostream>
#include "Command.h"
#include "SchoolClass.h"

class GradesCommand : public Command
{
public:
	GradesCommand(SchoolClass& schoolClass);

	void execute() override;

private:
	SchoolClass& schoolClass;
};

