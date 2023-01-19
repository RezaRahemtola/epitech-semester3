/*
** EPITECH PROJECT, 2023
** seminar
** File description:
** $DESCRIPTION
*/

#pragma once

#include "Student.hpp"

class Dean {
    public:
    Dean(std::string name);
    ~Dean();

    std::string getName(void);
    void teachStudent(Student *student, std::string lesson);
    void timeCheck(void);

    private:
    std::string _name;
    bool _working;
};
