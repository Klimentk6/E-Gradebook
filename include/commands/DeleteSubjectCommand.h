#pragma once
#include <iostream>
#include "Utils.h"
#include "Command.h"
#include "SchoolClass.h"

class DeleteSubjectCommand : public Command
{
public:
	DeleteSubjectCommand(SchoolClass& schoolClass);

	void execute() override;

private:
	std::string readName();

	SchoolClass& schoolClass;
};

