/*
** EPITECH PROJECT, 2023
** day09
** File description:
** reza
*/

#include <iostream>
#include "Peasant.hpp"

Peasant::Peasant(const std::string &name, int power) : name(name), power(std::min(std::max(power, 0), 100))
{
    std::cout << this->name << " goes for an adventure." << std::endl;
}

Peasant::~Peasant()
{
    std::cout << this->name << " is back to his crops." << std::endl;
}

const std::string &Peasant::getName() const
{
    return this->name;
}

int Peasant::getPower() const
{
    return this->power;
}

int Peasant::getHp() const
{
    return this->hp;
}

// Techniques
bool Peasant::canUseTechnique(int cost)
{
    if (this->hp == 0) {
        std::cout << this->name << " is out of combat." << std::endl;
        return false;
    }
    if (this->power < cost) {
        std::cout << this->name << " is out of power." << std::endl;
        return false;
    }
    this->power -= cost;
    return true;
}

int Peasant::attack()
{
    if (!canUseTechnique(10))
        return 0;
    std::cout << this->name << " tosses a stone." << std::endl;
    return 5;
}

int Peasant::special()
{
    if (!canUseTechnique(0))
        return 0;
    std::cout << this->name << " doesn't know any special move." << std::endl;
    return 0;
}

void Peasant::rest()
{
    if (!canUseTechnique(0))
        return;
    std::cout << this->name << " takes a nap." << std::endl;
    this->power = std::min(this->power + 30, 100);
}

void Peasant::damage(int damage)
{
    int newHp = std::min(std::max(this->hp - damage, 0), 100);

    if (newHp == 0) {
        std::cout << this->name << " is out of combat." << std::endl;
    } else {
        std::cout << this->name << " takes " << damage << " damage." << std::endl;
    }
    this->hp = newHp;
}

void Peasant::drink(const HealthPotion &potion)
{
    this->hp = std::max(std::min(this->hp + potion.getHp(), 100), 0);
    this->power = std::max(std::min(this->power + potion.getPower(), 100), 0);
    std::cout << this->name << " feels rejuvenated." << std::endl;
}

void Peasant::drink(const PowerPotion &potion)
{
    this->hp = std::max(std::min(this->hp + potion.getHp(), 100), 0);
    this->power = std::max(std::min(this->power + potion.getPower(), 100), 0);
    std::cout << this->name << "'s power is restored." << std::endl;
}

void Peasant::drink(const PoisonPotion &potion)
{
    this->hp = std::max(std::min(this->hp + potion.getHp(), 100), 0);
    this->power = std::max(std::min(this->power + potion.getPower(), 100), 0);
    std::cout << this->name << " has been poisoned." << std::endl;
}

void Peasant::drink(const IPotion &potion)
{
    this->hp = std::max(std::min(this->hp + potion.getHp(), 100), 0);
    this->power = std::max(std::min(this->power + potion.getPower(), 100), 0);
    std::cout << this->name << " drinks a mysterious potion." << std::endl;
}