/*
** EPITECH PROJECT, 2023
** day13
** File description:
** Command
*/

#include "Command.hpp"

void Command::registerCommand(const std::string &name, const std::function<void()> &function)
{
    if (this->map.count(name) > 0)
        throw Command::Error("Already registered command");
    this->map[name] = function;
}

void Command::executeCommand(const std::string &name)
{
    if (this->map.count(name) == 0)
        throw Command::Error("Unknow command");
    this->map[name]();
}
