#include "StudentsCommand.h"

StudentsCommand::StudentsCommand(SchoolClass& schoolClass)
 : schoolClass(schoolClass) {}

void StudentsCommand::execute()
{
	schoolClass.getStudents().printAllStudents();
}
