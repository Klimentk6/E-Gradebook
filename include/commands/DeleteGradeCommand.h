#pragma once
#include <iostream>
#include "Utils.h"
#include "Command.h"
#include "SchoolClass.h"

using namespace Utils;

class DeleteGradeCommand : public Command
{
public:
	DeleteGradeCommand(SchoolClass& schoolClass);

	void execute() override;

private:
	unsigned readIndex();

	SchoolClass& schoolClass;
};

