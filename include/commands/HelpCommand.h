#pragma once
#include <iostream>
#include "Command.h"
#include "SchoolClass.h"

class HelpCommand : public Command
{
public:
	HelpCommand(SchoolClass& schoolClass);

	void execute() override;

private:
	SchoolClass& schoolClass;
};

