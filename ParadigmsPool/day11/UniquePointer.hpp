/*
** EPITECH PROJECT, 2023
** day11
** File description:
** reza
*/

#pragma once

#include "IObject.hpp"

class UniquePointer {
    public:
        UniquePointer() = default;
        UniquePointer(IObject *obj);
        ~UniquePointer();

        void reset(IObject *_obj = nullptr);
        void swap(UniquePointer &ptr);

        IObject *operator->() const;
        IObject &operator*() const;
        UniquePointer &operator=(IObject *_obj);
    private:
        IObject *obj = nullptr;
};