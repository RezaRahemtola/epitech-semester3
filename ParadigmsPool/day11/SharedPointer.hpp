/*
** EPITECH PROJECT, 2023
** day11
** File description:
** SharedPointer
*/

#pragma once

#include <cstddef>

class SharedPointer {
    public:
        [[nodiscard]] std::size_t use_count() const noexcept;
};