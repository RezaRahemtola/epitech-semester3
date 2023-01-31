/*
** EPITECH PROJECT, 2023
** option
** File description:
** h
*/

#pragma once

#include <vector>
#include "IMonitorModule.hpp"

class Option {
    public:
        enum DisplayMode {
            TERMINAL,
            GRAPHICAL,
            NONE
        };

        static void help();
        static DisplayMode check_options(int argc, char **argv, std::vector<IMonitorModule *> &modules);
};
