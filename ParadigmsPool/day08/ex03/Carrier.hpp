/*
** EPITECH PROJECT, 2023
** ex03
** File description:
** $DESCRIPTION
*/

#pragma once

#include "Droid.hpp"

class Carrier {
    public:
        Carrier(std::string id = "");
        ~Carrier();

        std::string getId() const;
        size_t getEnergy() const;
        size_t getSpeed() const;

        Droid *&operator[](int position) const;
        bool operator()(int x, int y);

        Carrier &operator<<(Droid *&droid);
        Carrier &operator>>(Droid *&droid);

        void operator<<(size_t &energy);
        Carrier &operator~();
    private:
        std::string Id;
        size_t Energy;
        const size_t Attack;
        const size_t Toughness;
        size_t Speed;
        Droid **Droids;

        size_t getBoardedCount() const;
};

std::ostream &operator<<(std::ostream&stream, const Carrier &carrier);
