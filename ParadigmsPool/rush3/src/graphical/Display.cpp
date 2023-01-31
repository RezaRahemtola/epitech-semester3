/*
** EPITECH PROJECT, 2023
** Rush3
** File description:
** Display.cpp
*/

#include "Display.hpp"
#include "../Utils.hpp"

Graphical::Display::Display(std::vector<IMonitorModule *> &modules) : AMonitorDisplay(modules), _window(sf::RenderWindow(sf::VideoMode(1080, 720), "MyGKrellM")), _font(sf::Font())
{
    this->_window.setFramerateLimit(30);
    this->_font.loadFromFile("assets/font.ttf");
}

Graphical::Display::~Display()
{
    this->_window.close();
}

void Graphical::Display::displayLoop()
{
    while (this->isOpen()) {
        this->_window.clear();
        this->handleEvents();
        this->drawModules();
        this->_window.display();
    }
}

void Graphical::Display::drawModules()
{
    std::vector<DisplayItem> list = Utils::placeModules(this->modules, 1080, 720, 1);

    for (auto &item : list) {
        item.module.drawGraphical(this->_window, this->_font, *item.box);
        delete item.box;
    }
}

void Graphical::Display::handleEvents()
{
    sf::Event event {};

    while (this->_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            this->open = false;
        }
    }
}
