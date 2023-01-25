/*
** EPITECH PROJECT, 2023
** day10
** File description:
** reza
*/

#include "ACitrus.hpp"

#include <utility>

ACitrus::ACitrus(std::string name, unsigned int vitamins) : AFruit(std::move(name), vitamins)
{}