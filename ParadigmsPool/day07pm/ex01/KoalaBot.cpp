/*
** EPITECH PROJECT, 2023
** day07pm
** File description:
** $DESCRIPTION
*/

#include <iostream>
#include "KoalaBot.hpp"

KoalaBot::KoalaBot(std::string serial) : _serial(serial)
{
}

void KoalaBot::informations() const
{
    std::cout << "[KoalaBot] " << _serial << std::endl;
    this->arm.informations();
    this->leg.informations();
    this->head.informations();
}

bool KoalaBot::status() const
{
    return this->arm.isFunctional() && this->leg.isFunctional() && this->head.isFunctional();
}

void KoalaBot::setParts(const Arms &part)
{
    this->arm = part;
}

void KoalaBot::setParts(const Legs &part)
{
    this->leg = part;
}

void KoalaBot::setParts(const Head &part)
{
    this->head = part;
}

void KoalaBot::swapParts(Arms &part)
{
    Arms tmp = this->arm;

    this->arm = part;
    part = tmp;
}

void KoalaBot::swapParts(Legs &part)
{
    Legs tmp = this->leg;

    this->leg = part;
    part = tmp;
}

void KoalaBot::swapParts(Head &part)
{
    Head tmp = this->head;

    this->head = part;
    part = tmp;
}
