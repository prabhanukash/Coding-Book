#ifndef LOGGER_H
#define LOGGER_H

#include <string>

// Logger class for handling debug and release logging
class Logger
{
public:
    static void log(const std::string &message);

private:
    static void logToFile(const std::string &message);
};

#endif // LOGGER_H
