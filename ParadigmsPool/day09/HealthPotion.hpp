/*
** EPITECH PROJECT, 2023
** day09
** File description:
** reza
*/

#pragma once

#include "IPotion.hpp"

class HealthPotion : public IPotion {
    public:
        int getHp() const override;
        int getPower() const override;
};