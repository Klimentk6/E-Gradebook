#pragma once
#include <iostream>
#include <string>

class CommandValidations
{
public:
	static bool isValidHelpInput(const std::string& input);
	static bool isValidExitInput(const std::string& input);

	static bool isValidAddStudentInput(const std::string& input);
	static bool isValidEditStudentInput(const std::string& input);
	static bool isValidDeleteStudentInput(const std::string& input);
	static bool isValidStudentsInput(const std::string& input);

	static bool isValidAddSubjectInput(const std::string& input);
	static bool isValidEditSubjectInput(const std::string& input);
	static bool isValidDeleteSubjectInput(const std::string& input);
	static bool isValidSubjectsInput(const std::string& input);

	static bool isValidAddGradeInput(const std::string& input);
	static bool isValidEditGradeInput(const std::string& input);
	static bool isValidDeleteGradeInput(const std::string& input);
	static bool isValidGradesInput(const std::string& input);

	static bool isValidAverageGradeInput(const std::string& input);
	static bool isValidTotalGradeInput(const std::string& input);
	static bool isValidTopStudentsInput(const std::string& input);
	static bool isValidRemedialExamInput(const std::string& input);
	static bool isValidFailingStudentsInput(const std::string& input);
	static bool isValidBirthdayStudentsInput(const std::string& input);
};

