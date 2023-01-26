/*
** EPITECH PROJECT, 2023
** day11
** File description:
** reza
*/

#pragma once

#include <dirent.h>
#include "IDirectoryLister.hpp"

class DirectoryLister : public IDirectoryLister {
    public:
        DirectoryLister() = default;
        DirectoryLister(const std::string &path, bool hidden);
        ~DirectoryLister() override;

        bool open(const std::string &path, bool hidden) override;
        std::string get() override;
    private:
        bool hidden = false;
        DIR *dir = nullptr;
};