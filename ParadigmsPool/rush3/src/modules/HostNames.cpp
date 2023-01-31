/*
** EPITECH PROJECT, 2023
** Rush 3
** File description:
** HostNames.cpp
*/

#include <csignal>
#include <climits>
#include "HostNames.hpp"
#include "modules/ModuleError.hpp"

HostNames::HostNames() : AKeyValueDisplayedMonitorModule("Host names")
{}

void HostNames::refreshData()
{
    char *username = getlogin();
    char hostname[HOST_NAME_MAX + 1];

    if (!username)
        throw ModuleError("Cannot get username.");
    if (gethostname(hostname, HOST_NAME_MAX) == -1)
        throw ModuleError("Cannot get hostname.");
    this->data.clear();
    this->data.insert({"Username", username});
    this->data.insert({"Hostname", hostname});
}
