/*
** EPITECH PROJECT, 2023
** Rush 3
** File description:
** AMonitorDisplay.hpp
*/

#pragma once

#include <utility>
#include "IMonitorModule.hpp"

template<typename Type>
class AMonitorModule : public IMonitorModule {
    public:
        explicit AMonitorModule(std::string name) : name(std::move(name))
        {};
    protected:
        const std::string name;
        Type data;
};
