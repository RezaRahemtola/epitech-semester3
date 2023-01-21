/*
** EPITECH PROJECT, 2023
** day07pm
** File description:
** $DESCRIPTION
*/

#pragma once

#include "Parts.hpp"

class KoalaBot {
    public:
        KoalaBot(std::string serial = "Bob-01");

        void setParts(const Arms &part);
        void setParts(const Legs &part);
        void setParts(const Head &part);

        void swapParts(Arms &part);
        void swapParts(Legs &part);
        void swapParts(Head &part);

        void informations() const;
        bool status() const;

    private:
        Arms arm;
        Legs leg;
        Head head;
        std::string _serial = "Bob-01";
};
