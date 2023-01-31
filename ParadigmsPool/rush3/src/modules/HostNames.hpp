/*
** EPITECH PROJECT, 2023
** Rush 3
** File description:
** HostNames.hpp
*/

#pragma once

#include "AKeyValueDisplayedMonitorModule.hpp"

class HostNames : public AKeyValueDisplayedMonitorModule {
    public:
        HostNames();
        ~HostNames() override = default;

        void refreshData() override;
};
