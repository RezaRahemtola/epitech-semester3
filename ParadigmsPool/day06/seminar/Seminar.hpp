/*
** EPITECH PROJECT, 2023
** seminar
** File description:
** $DESCRIPTION
*/

#pragma once

#include <vector>
#include "Dean.hpp"
#include "Assistant.hpp"

class Seminar {
    public:
    void run(void);
    void addDean(Dean *dean);
    void addAssistant(Assistant *assitant);
    void addStudent(Student *student);

    private:
    Dean * _dean = nullptr;
    std::vector<Assistant *> _assistants;
    std::vector<Student *> _students;
};
