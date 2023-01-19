/*
** EPITECH PROJECT, 2023
** seminar
** File description:
** $DESCRIPTION
*/

#pragma once

#include <string>

class Student {
    public:
    Student(std::string name);
    ~Student();

    void drink(std::string name);
    bool learn(std::string text);
    std::string getName(void);

    private:
    std::string _name;
    unsigned int _energy;
};
