/*
** EPITECH PROJECT, 2023
** text
** File description:
** c
*/

#include <cstring>
#include <iostream>
#include <map>
#include "Option.hpp"
#include "modules/HostNames.hpp"
#include "modules/OperatingSystem.hpp"
#include "modules/DateTime.hpp"
#include "modules/Memory.hpp"

void Option::help()
{
    std::cout << "USAGE:" << std::endl;
    std::cout << "./MyGKrellm [OPTIONS] to process 3 options" << std::endl;
    std::cout << "OPTIONS:" << std::endl;
    std::cout << " -g | --graphical: Display the graphical window with SFML" << std::endl;
    std::cout << " -t | --terminal: Display the terminal window with ncurses" << std::endl;
    std::cout << " -h | --help: Print the usage and quit." << std::endl;
    std::cout << "MODULES:" << std::endl;
    std::cout << "--hostnames: Username and hostname" << std::endl;
    std::cout << "--os: Operating system name and version" << std::endl;
    std::cout << "--date: Date and time" << std::endl;
    std::cout << "--memory: Physical and swap memory usage" << std::endl;
}

Option::DisplayMode Option::check_options(int argc, char **argv, std::vector<IMonitorModule *> &modules)
{
    Option::DisplayMode mode = TERMINAL;
    std::map<std::string, IMonitorModule *> modulesMap = std::map<std::string, IMonitorModule *>();
    modulesMap["--hostnames"] = new HostNames();
    modulesMap["--os"] = new OperatingSystem();
    modulesMap["--date"] = new DateTime();
    modulesMap["--memory"] = new Memory();

    for (int i = 0; i < argc; i++) {
        if (strcmp("--terminal", argv[i]) == 0 || strcmp("-t", argv[i]) == 0) {
            mode = TERMINAL;
        } else if (strcmp("--graphical", argv[i]) == 0 || strcmp("-g", argv[i]) == 0) {
            mode = GRAPHICAL;
        } else if (strcmp("--help", argv[i]) == 0 || strcmp("-h", argv[i]) == 0) {
            help();
            return NONE;
        }
        if (modulesMap[argv[i]] != nullptr) {
            modules.push_back(modulesMap[argv[i]]);
            modulesMap[argv[i]] = nullptr;
        }
    }
    if (modules.empty()) {
        modules.push_back(new HostNames());
        modules.push_back(new OperatingSystem());
        modules.push_back(new DateTime());
        modules.push_back(new Memory());
    }
    return mode;
}
