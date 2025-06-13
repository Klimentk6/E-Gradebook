#pragma once
#include <iostream>
#include "Command.h"
#include "SchoolClass.h"

class TopStudentsCommand : public Command
{
public:
	TopStudentsCommand(SchoolClass& schoolClass);

	void execute() override;

private:
	SchoolClass& schoolClass;
};