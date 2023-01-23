/*
** EPITECH PROJECT, 2023
** day09
** File description:
** reza
*/

#pragma once

#include <string>
#include "ICharacter.hpp"

class Peasant : public ICharacter {
    public:
        Peasant(const std::string &name, int power);
        ~Peasant();

        const std::string &getName() const override;
        int getPower() const override;
        int getHp() const override;

        int attack() override;
        int special() override;
        void rest() override;
        void damage(int damage) override;

        void drink(const HealthPotion &potion) override;
        void drink(const PowerPotion &potion) override;
        void drink(const PoisonPotion &potion) override;
        void drink(const IPotion &potion) override;
    protected:
        const std::string name;
        int power;
        int hp = 100;

        bool canUseTechnique(int cost);

        Peasant() = default;
};