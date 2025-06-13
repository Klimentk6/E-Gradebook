#pragma once
#include <iostream>
#include "Command.h"
#include "SchoolClass.h"

class RemedialExamCommand : public Command 
{
public:
    RemedialExamCommand(SchoolClass& schoolClass);
    void execute() override;

private:
    std::string readSubjectName();

    SchoolClass& schoolClass;
};
