#include "HelpCommand.h"

HelpCommand::HelpCommand(SchoolClass& schoolClass)
	:schoolClass(schoolClass) {}

void HelpCommand::execute()
{
	std::cout << "All commands" << std::endl
		<< "-----------------" << std::endl
		<< "add_student" << std::endl
		<< "edit_student" << std::endl
		<< "delete_student" << std::endl
		<< "students" << std::endl
		<< "add_subject" << std::endl
		<< "edit_subject" << std::endl
		<< "delete_subject" << std::endl
		<< "subjeects" << std::endl
		<< "add_grade" << std::endl
		<< "edit_grade" << std::endl
		<< "delete_grade" << std::endl
		<< "grades" << std::endl
		<< "average_grade" << std::endl
		<< "total_grade" << std::endl
		<< "top_students" << std::endl
		<< "average_grade" << std::endl
		<< "remedial_exam" << std::endl
		<< "failing_sudents" << std::endl
		<< "birthday_students" << std::endl;
}
