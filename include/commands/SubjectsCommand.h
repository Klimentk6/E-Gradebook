#pragma once
#include <iostream>
#include "Command.h"
#include "SchoolClass.h"

class SubjectsCommand : public Command
{
public:
	SubjectsCommand(SchoolClass& schoolClass);

	void execute() override;

private:
	SchoolClass& schoolClass;
};

