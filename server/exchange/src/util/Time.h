#pragma once

#include <chrono>

namespace util
{
    std::string serializeTimePoint(const std::chrono::system_clock::time_point &time)
    {
        std::time_t t = std::chrono::system_clock::to_time_t(time);
        std::string timeString = std::ctime(&t);
        timeString.pop_back();
        return timeString;
    }
}