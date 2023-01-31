/*
** EPITECH PROJECT, 2023
** Rush 3
** File description:
** DateTime.hpp
*/

#pragma once

#include "AKeyValueDisplayedMonitorModule.hpp"

class DateTime : public AKeyValueDisplayedMonitorModule {
    public:
        DateTime();
        ~DateTime() override = default;

        void refreshData() override;
};
