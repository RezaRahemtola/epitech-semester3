/*
** EPITECH PROJECT, 2023
** Rush3
** File description:
** AMonitorModule.hpp
*/

#pragma once

#include <vector>
#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"

class AMonitorDisplay : public IMonitorDisplay {
    public:
        explicit AMonitorDisplay(std::vector<IMonitorModule *> &modules) : modules(modules) {};

        bool isOpen() override
        {
            return this->open;
        }

    protected:
        bool open = true;
        std::vector<IMonitorModule *> modules = std::vector<IMonitorModule *>();
};
