#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <string>

class FileManager
{
public:
    static bool writeFile(const std::string &filename, const std::string &content);
    static std::string readFile(const std::string &filename);
};
// Declaration of platform-specific function
void platformSpecificFunction();
#endif // FILE_MANAGER_H
