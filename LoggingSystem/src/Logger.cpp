#include "Logger.h"
#include "Config.h"
#include <fstream>

#ifdef DEBUG
#include <iostream>
#endif

void Logger::log(const std::string &message)
{
#ifdef DEBUG
    std::cout << "DEBUG: " << message << std::endl;
#else
    logToFile("INFO: " + message);
#endif
}

void Logger::logToFile(const std::string &message)
{
    std::ofstream logFile("log.txt", std::ios_base::app);
    if (logFile.is_open())
    {
        logFile << message << std::endl;
        logFile.close();
    }
}
