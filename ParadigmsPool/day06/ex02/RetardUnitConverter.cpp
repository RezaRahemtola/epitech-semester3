/*
** EPITECH PROJECT, 2023
** ex00
** File description:
** $DESCRIPTION
*/

#include <iostream>
#include <cstring>
#include <sstream>
#include <iomanip>

int main(int argc, char **argv)
{
    std::string truc;
    float temp;
    std::string unit;

    while (getline(std::cin, truc)) {
        std::stringstream ss(truc);
        ss >> temp >> unit;

        if (unit == "Fahrenheit") {
            std::cout << std::setw(16) << std::fixed << std::setprecision(3) << 5.0 / 9.0 * (temp - 32)
                      << std::setw(16) << " Celsius"
                      << std::endl;
        } else if (unit == "Celsius") {
            std::cout << std::setw(16) << std::fixed << std::setprecision(3) << temp * 9.0 / 5.0 + 32
                      << std::setw(16) << " Fahrenheit"
                      << std::endl;
        }
    }
}
