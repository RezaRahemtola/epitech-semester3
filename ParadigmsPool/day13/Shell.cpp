/*
** EPITECH PROJECT, 2023
** day13
** File description:
** Shell
*/

#include "Shell.hpp"

Shell::Shell(std::istream &istream) : stream(istream)
{}

void Shell::next()
{
    std::string data;

    if (!this->stream.good())
        throw Error("Input failed");

    getline(this->stream, data);

    if (this->stream.eof())
        throw Error("End of input");
    this->line = std::stringstream(data);
}
