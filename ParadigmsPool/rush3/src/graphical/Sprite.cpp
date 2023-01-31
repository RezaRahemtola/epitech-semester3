/*
** EPITECH PROJECT, 2023
** sprite
** File description:
** c
*/

#include "Sprite.hpp"

Sprite::Sprite(std::string file, int x, int y)
{
    _texture.loadFromFile(file);
    _sprite.setTexture(_texture);
    _sprite.setPosition(x, y);
}
