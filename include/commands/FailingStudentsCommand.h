#pragma once
#include <iostream>
#include "Command.h"
#include "SchoolClass.h"

class FailingStudentsCommand : public Command
{
public:
    FailingStudentsCommand(SchoolClass& schoolClass);

    void execute() override;

private:
    SchoolClass& schoolClass;
};
