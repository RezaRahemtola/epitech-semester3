/*
** EPITECH PROJECT, 2023
** day13
** File description:
** Stack
*/

#pragma once

#include <string>
#include <exception>
#include <stack>
#include <utility>

class Stack {
    public:
        void push(double value);
        double pop();
        [[nodiscard]] double top() const;
        void add();
        void sub();
        void mul();
        void div();

        class Error : public std::exception {
            public:
                explicit Error(std::string text) : text(std::move(text))
                {
                };

                [[nodiscard]] const char *what() const noexcept override
                {
                    return this->text.c_str();
                };
            private:
                std::string text;
        };

    private:
        std::stack<double> stack;
};