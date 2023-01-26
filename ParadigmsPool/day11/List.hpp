/*
** EPITECH PROJECT, 2023
** day11
** File description:
** reza
*/

#pragma once

#include <exception>
#include <string>
#include <list>
#include "IObject.hpp"

class List {
    public:
        List();
        ~List();
        [[nodiscard]] bool empty() const;
        [[nodiscard]] std::size_t size() const;
        IObject *&front();
        [[nodiscard]] IObject *front() const;
        IObject *&back();
        [[nodiscard]] IObject *back() const;
        void pushBack(IObject *obj);
        void pushFront(IObject *obj);
        void popFront();
        void popBack();
        void clear();
        void forEach(void(*function)(IObject *));

        class InvalidOperationException : public std::exception {
        };

    private:
        std::list<IObject *> list;
};