#pragma once

#include <vector>
#include <memory>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace core
{
    class Logger
    {
    public:
        static void init();

        static std::shared_ptr<spdlog::logger> &acquire()
        {
            return logger;
        }

    private:
        static std::shared_ptr<spdlog::logger> logger;
    };
};

#define LOG_TRACE(...) ::core::Logger::acquire()->trace(__VA_ARGS__)
#define LOG_INFO(...) ::core::Logger::acquire()->info(__VA_ARGS__)
#define LOG_WARN(...) ::core::Logger::acquire()->warn(__VA_ARGS__)
#define LOG_ERROR(...) ::core::Logger::acquire()->error(__VA_ARGS__)
#define LOG_CRITICAL(...) ::core::Logger::acquire()->critical(__VA_ARGS__)