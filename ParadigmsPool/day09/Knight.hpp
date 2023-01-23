/*
** EPITECH PROJECT, 2023
** day09
** File description:
** reza
*/

#pragma once

#include "Peasant.hpp"

class Knight : virtual public Peasant {
    public:
        Knight(const std::string &name, int power);
        ~Knight();

        int attack() override;
        int special() override;
        void rest() override;
};