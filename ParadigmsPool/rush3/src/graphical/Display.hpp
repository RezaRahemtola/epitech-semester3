/*
** EPITECH PROJECT, 2023
** Rush3
** File description:
** Display.hpp
*/

#pragma once

#include <SFML/Graphics.hpp>
#include "AMonitorDisplay.hpp"

namespace Graphical {
    class Display : public AMonitorDisplay {
    public:
        Display(std::vector<IMonitorModule *> &modules);
        ~Display() override;
        void displayLoop() override;
        void drawModules() override;

    private:
        sf::RenderWindow _window;
        sf::Font _font;

        void handleEvents();
    };
}
