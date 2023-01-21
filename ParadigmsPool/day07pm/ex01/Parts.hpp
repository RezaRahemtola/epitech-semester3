/*
** EPITECH PROJECT, 2023
** day07pm
** File description:
** $DESCRIPTION
*/

#pragma once

#include <string>

class Part {
    public:
        Part(const std::string &serial, bool functional, std::string name = "");

        bool isFunctional() const;
        std::string serial() const;
        void informations() const;

    private:
        std::string _serial;
        bool _functional;
        std::string _name;
};

class Arms : public Part {
    public:
        Arms(const std::string &serial = "A-01", bool functional = true);
};

class Legs : public Part {
    public:
        Legs(const std::string &serial = "L-01", bool functional = true);
};

class Head : public Part {
    public:
        Head(const std::string &serial = "H-01", bool functional = true);
};
