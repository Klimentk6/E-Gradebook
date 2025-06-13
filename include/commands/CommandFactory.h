#pragma once
#include <iostream>
#include <string>
#include "SchoolClass.h"
#include "Command.h"
#include "CommandValidations.h"
#include "HelpCommand.h"
#include "AddStudentCommand.h"
#include "EditStudentCommand.h"
#include "DeleteStudentCommand.h"
#include "StudentsCommand.h"
#include "AddSubjectCommand.h"
#include "EditSubjectCommand.h"
#include "DeleteSubjectCommand.h"
#include "SubjectsCommand.h"
#include "AddGradeCommand.h"
#include "EditGradeCommand.h"
#include "DeleteGradeCommand.h"
#include "GradesCommand.h"
#include "AverageGradeCommand.h"
#include "TotalGradeCommand.h"
#include "RemedialExamCommand.h"
#include "FailingStudentsCommand.h"
#include "TopStudentsCommand.h"
#include "BirthdayStudentsCommand.h"

class CommandFactory
{
public:
	static Command* createCommand(const std::string& input, SchoolClass& schoolClass);
};

