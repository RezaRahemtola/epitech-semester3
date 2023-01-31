/*
** EPITECH PROJECT, 2023
** Rush3
** File description:
** Utils.hpp
*/

#pragma once

#include <vector>
#include "IMonitorModule.hpp"

class DisplayItem {
    public:
        IMonitorModule &module;
        ModuleBox *box;
};

class Utils {
    public:
        static std::vector<DisplayItem> placeModules(std::vector<IMonitorModule *> &modules, int sizeX, int sizeY, int page);
};
