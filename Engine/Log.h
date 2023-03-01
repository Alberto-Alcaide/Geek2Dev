#ifndef LOG_H
#define LOG_H

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

class Log {
    public:
        static std::vector<LogEntry> messages;
        
        //It shows a message in green
        static void Info(const std::string& message); 

        // It shows a message in red
        static void Error(const std::string& message); 

        // It shows a message in yellow
        static void Warning(const std::string& message); 
};

#endif