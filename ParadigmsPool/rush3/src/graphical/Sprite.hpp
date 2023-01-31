/*
** EPITECH PROJECT, 2023
** sprite
** File description:
** h
*/

#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <string>

class Sprite {
    public :
        Sprite(std::string file, int x, int y);
        ~Sprite() = default;
    private:
        sf::Sprite _sprite;
        sf::Texture _texture;
};
