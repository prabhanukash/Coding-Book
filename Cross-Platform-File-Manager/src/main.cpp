#include "FileManager.h"
#include "Config.h"
#include <iostream>

int main()
{
    std::string filename = "test.txt";
    std::string content = "Hello, world!";

    if (FileManager::writeFile(filename, content))
    {
        std::cout << "File written successfully." << std::endl;
    }
    else
    {
        std::cout << "Failed to write file." << std::endl;
    }

    std::string readContent = FileManager::readFile(filename);
    if (!readContent.empty())
    {
        std::cout << "File read successfully: " << readContent << std::endl;
    }
    else
    {
        std::cout << "Failed to read file." << std::endl;
    }

    // Call platform-specific function
    platformSpecificFunction();

    return 0;
}
