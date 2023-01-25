/*
** EPITECH PROJECT, 2023
** day10
** File description:
** reza
*/

#pragma once

#include "FruitBox.hpp"
#include "IFruitMixer.hpp"

class FruitMixer : public IFruitMixer {
    public:
        unsigned int mixFruits(FruitBox &box) const override;
        void setBlade(IBlade *blade) override;
    private:
        IBlade *_blade = nullptr;
};
