/*
** EPITECH PROJECT, 2023
** ex00
** File description:
** $DESCRIPTION
*/

#include <fstream>
#include <iostream>
#include <cerrno>
#include <cstring>

int main(int argc, char **argv)
{
    std::string data;
    bool has_error = false;

    while (argc == 1 && std::getline(std::cin, data))
        std::cout << data << std::endl;
    for (int i = 1; i < argc; i++) {
        std::ifstream infile;
        infile.open(argv[i]);
        if (!infile.good()) {
            std::cerr << "MyCat: " << argv[i] << ": " << strerror(errno) << std::endl;
            has_error = true;
        } else {
            while (std::getline(infile, data)) {
                std::cout << data;
                if (!infile.eof())
                    std::cout << std::endl;
            }
        }
    }
    return (has_error ? 84 : 0);
}
