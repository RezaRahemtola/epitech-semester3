/*
** EPITECH PROJECT, 2023
** seminar
** File description:
** $DESCRIPTION
*/

#pragma once

#include "Student.hpp"

class Assistant {
    public:
    Assistant(int id);
    ~Assistant();

    int getId();
    void giveDrink(Student *student, std::string name);
    std::string readDrink(std::string student_name);
    void helpStudent(Student *student);
    void timeCheck(void);

    private:
    int _id;
    bool _working;
};
