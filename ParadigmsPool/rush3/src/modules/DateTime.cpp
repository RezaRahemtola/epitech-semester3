/*
** EPITECH PROJECT, 2023
** Rush 3
** File description:
** DateTime.hpp
*/

#include <chrono>
#include <ctime>
#include "DateTime.hpp"

DateTime::DateTime() : AKeyValueDisplayedMonitorModule("Date & Time")
{}

void DateTime::refreshData()
{
    std::time_t currentTime = std::time(nullptr);
    std::tm *timeStruct = std::localtime(&currentTime);
    std::string date = (timeStruct->tm_mday < 10 ? "0" : "") + std::to_string(timeStruct->tm_mday) + "/" +
                       (timeStruct->tm_mon < 10 ? "0" : "") + std::to_string(timeStruct->tm_mon + 1) + "/" +
                       std::to_string(timeStruct->tm_year + 1900);
    std::string time = (timeStruct->tm_hour < 10 ? "0" : "") + std::to_string(timeStruct->tm_hour) + ":" +
                       (timeStruct->tm_min < 10 ? "0" : "") + std::to_string(timeStruct->tm_min) + ":" +
                       (timeStruct->tm_sec < 10 ? "0" : "") + std::to_string(timeStruct->tm_sec);
    this->data.clear();
    this->data.insert({"Date", date});
    this->data.insert({"Time", time});
}
