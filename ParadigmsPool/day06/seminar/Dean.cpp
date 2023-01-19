/*
** EPITECH PROJECT, 2023
** seminar
** File description:
** $DESCRIPTION
*/

#include <iostream>
#include <fstream>
#include "Dean.hpp"

Dean::Dean(std::string name) : _name(name), _working(false)
{
    std::cout << "Dean " + _name
              << ": I'm Dean " + _name + "! How do you do, fellow kids?"
              << std::endl;
}

Dean::~Dean(void)
{
    std::cout << "Dean " << _name
              << ": Time to go home."
              << std::endl;
}

void Dean::teachStudent(Student *student, std::string lesson)
{
    std::string student_name = student->getName();
    std::string choices[5] = {"Cristaline", "Monster", "Evian", "Red Bull", "Sierra Springs"};

    if (!student->learn(lesson)) {
        std::cout << "Dean " << _name
                  << ": All work and no play makes "
                  << student_name
                  << " a dull student."
                  << std::endl;
        std::ofstream file(student_name + ".drink");
        file << choices[std::rand() % 5];
        file.close();
    }
}

void Dean::timeCheck(void)
{
    _working = !_working;

    if (_working) {
        std::cout << "Dean " << _name
                  << ": Where is everyone?"
                  << std::endl;
    } else {
        std::cout << "Dean " << _name
                  << ": Don't forget to close the windows when you leave."
                  << std::endl;
    }
}

std::string Dean::getName(void)
{
    return _name;
}
