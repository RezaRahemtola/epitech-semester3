/*
** EPITECH PROJECT, 2023
** Rush 3
** File description:
** Operating System
*/

#pragma once

#include <string>
#include "AMonitorModule.hpp"
#include "AKeyValueDisplayedMonitorModule.hpp"

class OperatingSystem : public AKeyValueDisplayedMonitorModule {
    public:
        OperatingSystem();
        ~OperatingSystem() override = default;

        void refreshData() override;
};
