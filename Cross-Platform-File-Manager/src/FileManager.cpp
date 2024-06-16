#include "FileManager.h"
#include "Config.h"
#include <fstream>
#include <iostream>

#ifdef WINDOWS
#include <windows.h>
#elif defined(UNIX)
#include <unistd.h>
#endif

bool FileManager::writeFile(const std::string &filename, const std::string &content)
{
    std::ofstream file(filename);
    if (file.is_open())
    {
        file << content;
        file.close();
        return true;
    }
    else
    {
        return false;
    }
}

std::string FileManager::readFile(const std::string &filename)
{
    std::ifstream file(filename);
    if (file.is_open())
    {
        std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        file.close();
        return content;
    }
    else
    {
        return "";
    }
}

#ifdef WINDOWS
void platformSpecificFunction()
{
    // Windows-specific code
    SYSTEMTIME time;
    GetSystemTime(&time);
    std::cout << "Windows System Time: " << time.wHour << ":" << time.wMinute << ":" << time.wSecond << std::endl;
}
#elif defined(UNIX)
void platformSpecificFunction()
{
    // Unix-specific code
    std::cout << "Unix System Time: " << time(nullptr) << std::endl;
}
#endif
