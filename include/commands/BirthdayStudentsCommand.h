#pragma once
#include <iostream>
#include "Command.h"
#include "SchoolClass.h"

class BirthdayStudentsCommand : public Command
{
public:
	BirthdayStudentsCommand(SchoolClass& schoolClass);

	void execute() override;

private:
	SchoolClass& schoolClass;
};


