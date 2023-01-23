/*
** EPITECH PROJECT, 2023
** day09
** File description:
** reza
*/

#pragma once

#include "IPotion.hpp"

class PoisonPotion : public IPotion {
    public:
        int getHp() const override;
        int getPower() const override;
};