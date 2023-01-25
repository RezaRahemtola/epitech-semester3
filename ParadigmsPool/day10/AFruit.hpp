/*
** EPITECH PROJECT, 2023
** day10
** File description:
** reza
*/

#pragma once

#include <string>
#include "IFruit.hpp"

class AFruit : public IFruit {
    public:
        unsigned int getVitamins() const override;
        std::string getName() const override;
        bool isPeeled() const override;
        void peel() override;

        IFruit *clone() const override;
    protected:
        AFruit(std::string name, unsigned int vitamins, bool peeled = false);

    private:
        bool peeled;
        unsigned int vitamins;
        std::string name;
};