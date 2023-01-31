/*
** EPITECH PROJECT, 2023
** text
** File description:
** h
*/

#pragma once

#include <SFML/Graphics/Text.hpp>

class Text {
    public :
        Text(sf::Font *font, int x, int y, int size, std::string str, sf::Color color);
        ~Text() = default;
    private:
        sf::Text _text;
};
