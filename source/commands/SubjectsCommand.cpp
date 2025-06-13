#include "SubjectsCommand.h"

SubjectsCommand::SubjectsCommand(SchoolClass& schoolClass)
	: schoolClass(schoolClass) {}

void SubjectsCommand::execute()
{
	schoolClass.getSubjects().printAllSubjects();
}
