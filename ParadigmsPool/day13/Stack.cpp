/*
** EPITECH PROJECT, 2023
** day13
** File description:
** Stack
*/

#include "Stack.hpp"

void Stack::push(double value)
{
    this->stack.push(value);
}

double Stack::pop()
{
    double elem = this->top();
    this->stack.pop();
    return elem;
}

double Stack::top() const
{
    if (this->stack.empty())
        throw Stack::Error("Empty stack");
    double elem = this->stack.top();
    return elem;
}

void Stack::add()
{
    if (this->stack.size() < 2)
        throw Error("Not enough operands");
    double elem1 = this->pop();
    double elem2 = this->pop();
    this->push(elem1 + elem2);
}

void Stack::sub()
{
    if (this->stack.size() < 2)
        throw Error("Not enough operands");
    double elem1 = this->pop();
    double elem2 = this->pop();
    this->push(elem1 - elem2);
}

void Stack::mul()
{
    if (this->stack.size() < 2)
        throw Error("Not enough operands");
    double elem1 = this->pop();
    double elem2 = this->pop();
    this->push(elem1 * elem2);
}

void Stack::div()
{
    if (this->stack.size() < 2)
        throw Error("Not enough operands");
    double elem1 = this->pop();
    double elem2 = this->pop();

    if (elem2 == 0) {
        this->push(elem2);
        this->push(elem1);
    }
    this->push(elem1 / elem2);
}