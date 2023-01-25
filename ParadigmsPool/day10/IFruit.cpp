/*
** EPITECH PROJECT, 2023
** day10
** File description:
** reza
*/

#include <iostream>
#include "IFruit.hpp"

std::ostream &operator<<(std::ostream &stream, const IFruit &fruit)
{
    std::string peeled = fruit.isPeeled() ? "true" : "false";

    stream << "[name: \"" << fruit.getName() << "\", vitamins: " << fruit.getVitamins() << ", peeled: "
           << peeled << "]";
    return stream;
}