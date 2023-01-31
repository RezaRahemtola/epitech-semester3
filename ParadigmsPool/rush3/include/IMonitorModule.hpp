/*
** EPITECH PROJECT, 2023
** Rush 3
** File description:
** IMonitorDisplay.hpp
*/

#pragma once

#include <ncurses.h>
#include <SFML/Graphics.hpp>
#include <string>

struct ModuleBox {
    int startX;
    int startY;
    int endX;
    int endY;
};

class IMonitorModule {
    public:
        virtual ~IMonitorModule() = default;
        virtual void refreshData() = 0;
        virtual void drawText(ModuleBox modBox) = 0;
        virtual void drawGraphical(sf::RenderWindow &window, const sf::Font &font, ModuleBox box) = 0;
};
