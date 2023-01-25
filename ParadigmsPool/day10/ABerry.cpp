/*
** EPITECH PROJECT, 2023
** day10
** File description:
** reza
*/

#include "ABerry.hpp"

#include <utility>

ABerry::ABerry(std::string name, unsigned vitamins) : AFruit(std::move(name), vitamins, true)
{}