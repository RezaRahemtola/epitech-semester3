/*
** EPITECH PROJECT, 2023
** day12
** File description:
** Toy
*/

#pragma once

#include "Picture.hpp"

class Toy {
    public:
        enum ToyType {
            BASIC_TOY,
            ALIEN
        };
        Toy();
        Toy(ToyType _type, std::string _name, const std::string &file);

        [[nodiscard]] ToyType getType() const;
        [[nodiscard]] std::string getName() const;
        void setName(std::string _name);
        bool setAscii(const std::string &file);
        [[nodiscard]] std::string getAscii() const;
    private:
        ToyType type;
        std::string name;
        Picture picture;
};