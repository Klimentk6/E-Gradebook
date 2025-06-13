#include <iostream>
#include <string>
#include "SchoolClass.h"
#include "Command.h"
#include "CommandFactory.h"
#include "CommandValidations.h"

int main()
{
    std::cout << "E-Gradebook" << std::endl;
    SchoolClass schoolClass;
    std::string input;
    while (true)
    {
        std::cout << "> ";
        std::getline(std::cin, input);
        if (CommandValidations::isValidExitInput(input)) break;
        Command* command = CommandFactory::createCommand(input, schoolClass);
        if (command)
        {
            command->execute();
            delete command;
        }
    }
    return 0;
}