/*
** EPITECH PROJECT, 2023
** day12
** File description:
** Picture
*/

#pragma once

#include <string>

class Picture {
    public:
        Picture() = default;
        explicit Picture(const std::string &file);

        std::string data;
        bool getPictureFromFile(const std::string &file);
};