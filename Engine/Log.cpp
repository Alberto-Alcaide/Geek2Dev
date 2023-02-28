#include "Log.h"
#include <iostream>
#include <string>
#include <chrono>
#include <ctime>

std::vector<LogEntry> Log::messages;

std::string CurrentDateTimeToString() {
    std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::string output(30, '\01');
    std::strftime(&output[0], output.size(), "%d-%b-%Y %H:%M:%S", std::localtime(&now));
    return output;
}

void Log::Info(const std::string& message) {
    LogEntry logEntry;
    logEntry.type = LOG_INFO;
    logEntry.message = "INF [" +CurrentDateTimeToString() + "]: " + message;
    std::cout << "\x1B[32m" << logEntry.message << "\033[0m" << std::endl;
    messages.push_back(logEntry);
}

void Log::Error(const std::string& message) {
    LogEntry logEntry;
    logEntry.type = LOG_ERROR;
    logEntry.message = "INF [" +CurrentDateTimeToString() + "]: " + message;
    messages.push_back(logEntry);
    std::cerr << "\x1B[91m" << logEntry.message << "\033[0m" << std::endl;
}

void Log::Warning(const std::string& message) {
    LogEntry logEntry;
    logEntry.type = LOG_WARNING;
    logEntry.message = "INF [" +CurrentDateTimeToString() + "]: " + message;
    messages.push_back(logEntry);
    std::cerr << "\x1B[91m" << logEntry.message << "\033[0m" << std::endl;
}