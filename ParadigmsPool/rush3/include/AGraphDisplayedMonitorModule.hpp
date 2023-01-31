/*
** EPITECH PROJECT, 2023
** Rush 3
** File description:
** AGraphDisplayedModule.hpp
*/

#pragma once

#include <list>
#include "AMonitorModule.hpp"

class AGraphDisplayedMonitorModule : public AMonitorModule<std::vector<double>> {
    public:
        explicit AGraphDisplayedMonitorModule(const std::string &name) : AMonitorModule(name)
        {}

        void drawText(ModuleBox box) final
        {
        }

        void drawGraphical(sf::RenderWindow &window, const sf::Font &font, ModuleBox box) final
        {

        }
};
