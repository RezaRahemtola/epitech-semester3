/*
** EPITECH PROJECT, 2023
** day11
** File description:
** SafeDirectoryLister
*/

#include "SafeDirectoryLister.hpp"

SafeDirectoryLister::SafeDirectoryLister(const std::string &path, bool hidden) : hidden(hidden)
{
    this->open(path, hidden);
};

SafeDirectoryLister::~SafeDirectoryLister()
{
    if (this->dir != nullptr)
        closedir(this->dir);
};

bool SafeDirectoryLister::open(const std::string &path, bool _hidden)
{
    this->hidden = _hidden;

    if (this->dir != nullptr)
        closedir(this->dir);

    this->dir = opendir(path.c_str());

    if (this->dir == nullptr)
        throw OpenFailureException();

    return true;
};

std::string SafeDirectoryLister::get()
{
    if (this->dir == nullptr)
        throw OpenFailureException();

    struct dirent *current = readdir(this->dir);

    if (current == nullptr)
        throw NoMoreFileException();
    if (!this->hidden && current->d_name[0] == '.')
        return this->get();
    return current->d_name;
};