/*
** EPITECH PROJECT, 2023
** day11
** File description:
** reza
*/

#include "DirectoryLister.hpp"

DirectoryLister::DirectoryLister(const std::string &path, bool hidden) : hidden(hidden)
{
    this->open(path, hidden);
}

bool DirectoryLister::open(const std::string &path, bool _hidden)
{
    this->hidden = _hidden;

    if (this->dir != nullptr)
        closedir(this->dir);

    this->dir = opendir(path.c_str());

    if (this->dir == nullptr) {
        perror(path.c_str());
        return false;
    }
    return true;
}

std::string DirectoryLister::get()
{
    if (this->dir == nullptr)
        return "";

    struct dirent *current = readdir(this->dir);

    if (current == nullptr)
        return "";
    if (!this->hidden && current->d_name[0] == '.')
        return this->get();
    return current->d_name;
}

DirectoryLister::~DirectoryLister()
{
    if (this->dir != nullptr)
        closedir(this->dir);
}
