/*
** EPITECH PROJECT, 2023
** ex01
** File description:
** $DESCRIPTION
*/

#include <iostream>
#include <random>
#include "DroidMemory.hpp"

size_t DroidMemory::getFingerprint() const
{
    return this->Fingerprint;
}

size_t DroidMemory::getExp() const
{
    return this->Exp;
}

void DroidMemory::setFingerprint(size_t fingerprint)
{
    this->Fingerprint = fingerprint;
}

void DroidMemory::setExp(size_t exp)
{
    this->Exp = exp;
}


// Operators
void DroidMemory::operator<<(DroidMemory &droid)
{
    this->Exp += droid.Exp;
    droid.Fingerprint = droid.Fingerprint ^ this->Fingerprint;
}

void DroidMemory::operator>>(DroidMemory &droid)
{
    droid.Exp += this->Exp;
    this->Fingerprint = this->Fingerprint ^ droid.Fingerprint;
}

void DroidMemory::operator+=(DroidMemory &droid)
{
    this->Exp += droid.Exp;
    droid.Fingerprint = droid.Fingerprint ^ this->Fingerprint;
}

void DroidMemory::operator+=(size_t exp)
{
    this->Exp += exp;
    this->Fingerprint = exp ^ this->Fingerprint;
}

DroidMemory DroidMemory::operator+(DroidMemory &droid) const
{
    DroidMemory *mem = new DroidMemory();

    mem->Exp = this->Exp + droid.Exp;
    mem->Fingerprint = droid.Fingerprint ^ this->Fingerprint;
    return *mem;
}

DroidMemory DroidMemory::operator+(size_t exp) const
{
    DroidMemory *mem = new DroidMemory();

    mem->Exp = this->Exp + exp;
    mem->Fingerprint = exp ^ this->Fingerprint;
    return *mem;
}

DroidMemory::DroidMemory() : Exp(0), Fingerprint(random())
{
}

DroidMemory::DroidMemory(const DroidMemory &mem) : Exp(mem.Exp), Fingerprint(mem.Fingerprint)
{
}

std::ostream &operator<<(std::ostream&stream, const DroidMemory &mem)
{
    return stream << "DroidMemory '" << mem.getFingerprint() << "', " << mem.getExp();
}

DroidMemory &DroidMemory::operator=(const DroidMemory &source)
{
    this->Exp = source.Exp;
    this->Fingerprint = source.Fingerprint;
    return *this;
}

bool DroidMemory::operator==(const DroidMemory &droid) const
{
    return this->Exp == droid.Exp && this->Fingerprint == droid.Fingerprint;
}

bool DroidMemory::operator!=(const DroidMemory &droid) const
{
    return !(*this == droid);
}

bool DroidMemory::operator<(const DroidMemory &droid) const
{
    return this->Exp < droid.Exp;
}

bool DroidMemory::operator<(size_t exp) const
{
    return this->Exp < exp;
}

bool DroidMemory::operator>(const DroidMemory &droid) const
{
    return this->Exp > droid.Exp;
}

bool DroidMemory::operator>(size_t exp) const
{
    return this->Exp > exp;
}

bool DroidMemory::operator<=(const DroidMemory &droid) const
{
    return this->Exp <= droid.Exp;
}

bool DroidMemory::operator<=(size_t exp) const
{
    return this->Exp <= exp;
}

bool DroidMemory::operator>=(const DroidMemory &droid) const
{
    return this->Exp >= droid.Exp;
}

bool DroidMemory::operator>=(size_t exp) const
{
    return this->Exp >= exp;
}
