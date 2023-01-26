/*
** EPITECH PROJECT, 2023
** day11
** File description:
** reza
*/

#include "UniquePointer.hpp"

UniquePointer::UniquePointer(IObject *obj) : obj(obj)
{}

UniquePointer::~UniquePointer()
{
    delete this->obj;
}

void UniquePointer::reset(IObject *_obj)
{
    delete this->obj;
    this->obj = _obj;
}

void UniquePointer::swap(UniquePointer &ptr)
{
    IObject *tmp = this->obj;

    this->obj = ptr.obj;
    ptr.obj = tmp;
}

IObject *UniquePointer::operator->() const
{
    return this->obj;
}

IObject &UniquePointer::operator*() const
{
    return *this->obj;
}

UniquePointer &UniquePointer::operator=(IObject *_obj)
{
    delete this->obj;
    this->obj = _obj;
    return *this;
}