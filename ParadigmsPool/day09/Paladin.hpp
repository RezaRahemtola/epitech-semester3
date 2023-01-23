/*
** EPITECH PROJECT, 2023
** day09
** File description:
** reza
*/

#pragma once

#include "Knight.hpp"
#include "Priest.hpp"

class Paladin : public Knight, public Priest {
    public:
        Paladin(const std::string &name, int power);
        ~Paladin();

        int attack() override;
        int special() override;
        void rest() override;
};