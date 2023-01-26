/*
** EPITECH PROJECT, 2023
** day11
** File description:
** reza
*/

#pragma once

#include <dirent.h>
#include "IDirectoryLister.hpp"

class SafeDirectoryLister : public IDirectoryLister {
    public:
        SafeDirectoryLister() = default;
        SafeDirectoryLister(const std::string &path, bool hidden);

        ~SafeDirectoryLister() override;

        bool open(const std::string &path, bool _hidden) override;

        std::string get() override;
    private:
        bool hidden = false;
        DIR *dir = nullptr;
};