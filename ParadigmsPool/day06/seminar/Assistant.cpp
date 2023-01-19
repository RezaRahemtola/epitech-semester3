/*
** EPITECH PROJECT, 2023
** seminar
** File description:
** $DESCRIPTION
*/

#include <fstream>
#include <iostream>
#include "Assistant.hpp"

Assistant::Assistant(int id) : _id(id), _working(false)
{
    std::cout << "Assistant " << _id
              << ": 'morning everyone *sip coffee*"
              << std::endl;
}

Assistant::~Assistant(void)
{
    std::cout << "Assistant " << _id
              << ": see you tomorrow at 9.00 *sip coffee*"
              << std::endl;
}

void Assistant::giveDrink(Student *student, std::string name)
{
    std::cout << "Assistant " << _id
              << ": drink this, " + student->getName() + " *sip coffee*"
              << std::endl;
    student->drink(name);
}

std::string Assistant::readDrink(std::string student_name)
{
    std::ifstream infile;
    std::string drink;

    infile.open(student_name + ".drink");

    if (!infile.good())
        return ("");

    std::getline(infile, drink);
    std::cout << "Assistant " << _id
              << ": " + student_name + " needs a "
              << drink
              << " *sip coffee*"
              << std::endl;
    remove((student_name + ".drink").c_str());
    return (drink);
}

void Assistant::helpStudent(Student *student)
{
    std::string student_name = student->getName();
    std::string drink = readDrink(student_name);

    if (drink == "") {
         std::cout << "Assistant " << _id
                   << ": " + student_name + " seems fine *sip coffee*"
                   << std::endl;
    } else {
        giveDrink(student, drink);
    }
}

void Assistant::timeCheck(void)
{
    _working = !_working;

    if (_working) {
        std::cout << "Assistant " << _id
                  << ": Time to teach some serious business *sip coffee*"
                  << std::endl;
    } else {
        std::cout << "Assistant " << _id
                  << ": Enough teaching for today *sip coffee*"
                  << std::endl;
    }
}

int Assistant::getId(void)
{
    return _id;
}
