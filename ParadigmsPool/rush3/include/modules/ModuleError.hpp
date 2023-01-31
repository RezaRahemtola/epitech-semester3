/*
** EPITECH PROJECT, 2023
** Rush 3
** File description:
** Module error
*/

#pragma once

#include <string>
#include <exception>
#include <utility>

class ModuleError : std::exception {
    public:
        explicit ModuleError(std::string what) : whatValue(std::move(what))
        {}

        [[nodiscard]] const char *what() const noexcept override
        {
            return this->whatValue.c_str();
        }

    private:
        const std::string whatValue;
};
