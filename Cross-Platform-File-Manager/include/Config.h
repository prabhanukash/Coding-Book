#ifndef CONFIG_H
#define CONFIG_H

// Define operating system
#if defined(_WIN32) || defined(_WIN64)
#define WINDOWS
#elif defined(__linux__) || defined(__APPLE__)
#define UNIX
#else
#error "Unknown operating system"
#endif

#endif // CONFIG_H
