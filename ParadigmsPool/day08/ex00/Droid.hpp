/*
** EPITECH PROJECT, 2023
** ex00
** File description:
** $DESCRIPTION
*/

#pragma once

#include <string>

class Droid {
    public:
        Droid(std::string serial = "");
        Droid(const Droid &d);
        ~Droid();

        std::string getId() const;
        void setId(std::string id);
        std::size_t getEnergy() const;
        void setEnergy(std::size_t);
        std::size_t getAttack() const;
        std::size_t getToughness() const;
        std::string *getStatus() const;
        void setStatus(std::string *status);

        Droid &operator=(const Droid &source);
        bool operator==(const Droid &other) const;
        bool operator!=(const Droid &newDroid) const;
        void operator<<(std::size_t &amount);

    private:
        std::string Id;
        std::size_t Energy = 50;
        const std::size_t Attack = 25;
        const std::size_t Toughness = 15;
        std::string *Status = new std::string("Standing by");
};

std::ostream &operator<<(std::ostream&stream, const Droid &droid);
