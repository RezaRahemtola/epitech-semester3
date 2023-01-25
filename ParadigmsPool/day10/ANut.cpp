/*
** EPITECH PROJECT, 2023
** day10
** File description:
** reza
*/

#include "ANut.hpp"

#include <utility>

ANut::ANut(std::string name, unsigned int vitamins) : AFruit(std::move(name), vitamins)
{}