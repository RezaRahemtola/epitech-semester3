/*
** EPITECH PROJECT, 2023
** seminar
** File description:
** $DESCRIPTION
*/

#include <iostream>
#include "Seminar.hpp"

void Seminar::addDean(Dean *dean)
{
    if (_dean != nullptr) {
        std::cout << "Seminar: There can only be one Dean of Studies."
                  << std::endl;
        return;
    }
    _dean = dean;
    std::cout << "Seminar: Dean " + dean->getName() + " is here."
              << std::endl;
}

void Seminar::addAssistant(Assistant *assistant)
{
    for (auto a :_assistants) {
        if (a->getId() == assistant->getId()) {
            std::cout << "Seminar: Assistant "
                      << assistant->getId()
                      << " is already registered."
                      << std::endl;
            return;
        }
    }

    if (_assistants.size() == 2) {
        std::cout << "Seminar: There is only room for two Teaching Assistants."
                  << std::endl;
        return;
    }

    _assistants.push_back(assistant);
    std::cout << "Seminar: Assistant "
              << assistant->getId()
              << " joined the pedagogical team."
              << std::endl;
}

void Seminar::addStudent(Student *student)
{
    for (auto a :_students) {
        if (a->getName() == student->getName()) {
            std::cout << "Seminar: Student "
                      << student->getName()
                      << " is already registered."
                      << std::endl;
            return;
        }
    }

    if (_students.size() == 5) {
        std::cout << "Seminar: There is only room for five Students."
                  << std::endl;
        return;
    }

    std::cout << "Seminar: Student "
              << student->getName()
              << " joined the seminar."
              << std::endl;
    _students.push_back(student);

}

void Seminar::run(void)
{
    if (_dean == nullptr || _assistants.size() == 0 || _students.size() == 0) {
        std::cout << "Seminar: A C++ seminar needs at least one Dean of Studies, one Assistant and one Student."
                  << std::endl;
        return;
    }

    // Beginning
    std::cout << "Seminar: Begining 6th day of seminar." << std::endl;
    std::cout << "Dean of Studies: " + _dean->getName() << std::endl;
    std::cout << "Teaching assistants: ";
    for (auto a :_assistants) {
        std::cout << a->getId();
        if (_assistants.back() == a)
            std::cout << std::endl;
        else
            std::cout << ", ";
    }
    std::cout << "Students: ";
    for (auto s:_students) {
        std::cout << s->getName();
        if (_students.back() == s)
            std::cout << std::endl;
        else
            std::cout << ", ";
    }

    // Time check
    _dean->timeCheck();
    for (auto a:_assistants)
        a->timeCheck();

    size_t curr_assistant = 0;
    for (size_t i = 0; i < 5; i++) {
        for (auto s:_students) {
            _dean->teachStudent(s, "I'm learning C++!");
            _assistants.at(curr_assistant)->helpStudent(s);
            curr_assistant = curr_assistant != _assistants.size() - 1 ? curr_assistant + 1 : 0;
        }
    }

    // Time check
    _dean->timeCheck();
    for (auto a:_assistants)
        a->timeCheck();
}
