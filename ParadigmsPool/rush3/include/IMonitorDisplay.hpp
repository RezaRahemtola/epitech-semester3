/*
** EPITECH PROJECT, 2023
** Rush3
** File description:
** IMonitorDisplay.hpp
*/

#pragma once

#include "IMonitorModule.hpp"

class IMonitorDisplay {
    public:
        virtual ~IMonitorDisplay() = default;
        virtual void drawModules() = 0;
        virtual void displayLoop() = 0;
        virtual bool isOpen() = 0;
};
