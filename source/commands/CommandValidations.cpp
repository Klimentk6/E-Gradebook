#include "CommandValidations.h"

bool CommandValidations::isValidHelpInput(const std::string& input)
{
    return input == "help";
}
bool CommandValidations::isValidExitInput(const std::string& input)
{
    return input == "exit";
}
bool CommandValidations::isValidAddStudentInput(const std::string& input)
{
    return input == "add_student";
}
bool CommandValidations::isValidEditStudentInput(const std::string& input)
{
    return input == "edit_student";
}
bool CommandValidations::isValidDeleteStudentInput(const std::string& input)
{
    return input == "delete_student";
}
bool CommandValidations::isValidStudentsInput(const std::string& input)
{
    return input == "students";
}
bool CommandValidations::isValidAddSubjectInput(const std::string& input)
{
    return input == "add_subject";
}
bool CommandValidations::isValidEditSubjectInput(const std::string& input)
{
    return input == "edit_subject";
}
bool CommandValidations::isValidDeleteSubjectInput(const std::string& input)
{
    return input == "delete_subject";
}
bool CommandValidations::isValidSubjectsInput(const std::string& input)
{
    return input == "subjects";
}

bool CommandValidations::isValidAddGradeInput(const std::string& input)
{
    return input == "add_grade";
}
bool CommandValidations::isValidEditGradeInput(const std::string& input)
{
    return input == "edit_grade";
}
bool CommandValidations::isValidGradesInput(const std::string& input)
{
    return input == "grades";
}
bool CommandValidations::isValidDeleteGradeInput(const std::string& input)
{
    return input == "delete_grade";
}
bool CommandValidations::isValidAverageGradeInput(const std::string& input)
{
    return input == "average_grade";
}
bool CommandValidations::isValidTotalGradeInput(const std::string& input)
{
    return input == "total_grade";
}
bool CommandValidations::isValidTopStudentsInput(const std::string& input)
{
    return input == "top_students";
}
bool CommandValidations::isValidRemedialExamInput(const std::string& input)
{
    return input == "remedial_exam";
}
bool CommandValidations::isValidFailingStudentsInput(const std::string& input)
{
    return input == "failing_students";
}
bool CommandValidations::isValidBirthdayStudentsInput(const std::string& input)
{
    return input == "birthday_students";
}

