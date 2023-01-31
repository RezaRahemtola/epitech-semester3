/*
** EPITECH PROJECT, 2023
** Rush 3
** File description:
** Operating System
*/

#include <sys/utsname.h>
#include "OperatingSystem.hpp"
#include "modules/ModuleError.hpp"

OperatingSystem::OperatingSystem() : AKeyValueDisplayedMonitorModule("Operating System")
{}

void OperatingSystem::refreshData()
{
    struct utsname info{};

    if (uname(&info) == -1)
        throw ModuleError("Cannot get operating system info.");

    this->data.clear();
    this->data.insert({"OS Name", info.sysname});
    this->data.insert({"Kernel version", info.release});
}
