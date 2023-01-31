/*
** EPITECH PROJECT, 2023
** text
** File description:
** c
*/

#include "Text.hpp"

Text::Text(sf::Font *font, int x, int y, int size, std::string str, sf::Color color)
{
    _text.setFont(*font);
    _text.setString(str);
    _text.setCharacterSize(size);
    _text.setPosition(x, y);
    _text.setFillColor(color);
}
