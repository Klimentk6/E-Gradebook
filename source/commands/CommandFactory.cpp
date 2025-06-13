#include "CommandFactory.h"

Command* CommandFactory::createCommand(const std::string& input, SchoolClass& schoolClass)
{
    if (CommandValidations::isValidHelpInput(input))
    {
        return new HelpCommand(schoolClass);
    }
    else if (CommandValidations::isValidAddStudentInput(input))
    {
        return new AddStudentCommand(schoolClass);
    }
    else if (CommandValidations::isValidEditStudentInput(input))
    {
        return new EditStudentCommand(schoolClass);
    }
    else if (CommandValidations::isValidDeleteStudentInput(input))
    {
        return new DeleteStudentCommand(schoolClass);
    }
    else if (CommandValidations::isValidStudentsInput(input))
    {
        return new StudentsCommand(schoolClass);
    }
    else if (CommandValidations::isValidAddSubjectInput(input))
    {
        return new AddSubjectCommand(schoolClass);
    }
    else if (CommandValidations::isValidEditSubjectInput(input))
    {
        return new EditSubjectCommand(schoolClass);
    }
    else if (CommandValidations::isValidDeleteSubjectInput(input))
    {
        return new DeleteSubjectCommand(schoolClass);
    }
    else if (CommandValidations::isValidSubjectsInput(input))
    {
        return new SubjectsCommand(schoolClass);
    }
    else if (CommandValidations::isValidAddGradeInput(input))
    {
        return new AddGradeCommand(schoolClass);
    }
    else if (CommandValidations::isValidEditGradeInput(input))
    {
        return new EditGradeCommand(schoolClass);
    }
    else if (CommandValidations::isValidDeleteGradeInput(input))
    {
        return new DeleteGradeCommand(schoolClass);
    }
    else if (CommandValidations::isValidGradesInput(input))
    {
        return new GradesCommand(schoolClass);
    }
    else if (CommandValidations::isValidAverageGradeInput(input))
    {
        return new AverageGradeCommand(schoolClass);
    }
    else if (CommandValidations::isValidTotalGradeInput(input))
    {
        return new TotalGradeCommand(schoolClass);
    }
    else if (CommandValidations::isValidTopStudentsInput(input))
    {
        return new TopStudentsCommand(schoolClass);
    }
    else if (CommandValidations::isValidRemedialExamInput(input))
    {
        return new RemedialExamCommand(schoolClass);
    }
    else if (CommandValidations::isValidFailingStudentsInput(input))
    {
        return new FailingStudentsCommand(schoolClass);
    }
    else if (CommandValidations::isValidBirthdayStudentsInput(input))
    {
        return new BirthdayStudentsCommand(schoolClass);
    }
    else
    {
        std::cout << "Invalid command!" << std::endl;
        return nullptr;
    }
}
