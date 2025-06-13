#include "BirthdayStudentsCommand.h"

BirthdayStudentsCommand::BirthdayStudentsCommand(SchoolClass& schoolClass)
	:schoolClass(schoolClass) {}

void BirthdayStudentsCommand::execute()
{
	schoolClass.getStudents().printBirthdayStudents();
}
