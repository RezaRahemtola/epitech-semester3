/*
** EPITECH PROJECT, 2023
** day11
** File description:
** reza
*/

#include "List.hpp"

List::List() : list(std::list<IObject *>())
{
}


List::~List()
{
    for (IObject *obj: this->list)
        delete obj;
}

bool List::empty() const
{
    return this->list.empty();
}

std::size_t List::size() const
{
    return this->list.size();
}

IObject *&List::front()
{
    if (this->empty())
        throw InvalidOperationException();
    return this->list.front();
}

IObject *List::front() const
{
    if (this->empty())
        throw InvalidOperationException();
    return this->list.front();
}

IObject *&List::back()
{
    if (this->empty())
        throw InvalidOperationException();
    return this->list.back();
}

IObject *List::back() const
{
    if (this->empty())
        throw InvalidOperationException();
    return this->list.back();
}

void List::pushBack(IObject *obj)
{
    this->list.push_back(obj);
}

void List::pushFront(IObject *obj)
{
    this->list.push_front(obj);
}

void List::popFront()
{
    if (this->empty())
        throw InvalidOperationException();
    IObject *elem = this->list.front();
    delete elem;
    this->list.pop_front();

}

void List::popBack()
{
    if (this->empty())
        throw InvalidOperationException();
    IObject *elem = this->list.back();
    delete elem;
    this->list.pop_back();
}

void List::clear()
{
    for (IObject *obj: this->list)
        delete obj;
    this->list.clear();
}

void List::forEach(void (*function)(IObject *))
{
    for (IObject *obj: this->list)
        function(obj);
}