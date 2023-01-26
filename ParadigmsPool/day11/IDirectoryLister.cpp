/*
** EPITECH PROJECT, 2023
** day11
** File description:
** reza
*/

#include <cstring>
#include "IDirectoryLister.hpp"

const char *IDirectoryLister::OpenFailureException::what() const noexcept
{
    return strerror(errno);
}

const char *IDirectoryLister::NoMoreFileException::what() const noexcept
{
    return "End of stream";
}