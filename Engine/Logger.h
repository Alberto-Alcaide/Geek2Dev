#ifndef LOGGER_H
#define LOGGER_H

#include <vector>
#include <string>

enum LogType {
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR
};

struct LogEntry
{
    LogType type;
    std::string message;
};

class Logger {
    public:
        static std::vector<LogEntry> messages;
        static void Info(const std::string& message);
        static void Error(const std::string& message);
        static void Warning(const std::string& message);
};

#endif