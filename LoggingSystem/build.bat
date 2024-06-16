@echo off
set INCLUDE_PATH=include
set SRC_PATH=src

g++ -I%INCLUDE_PATH% -o my_program %SRC_PATH%\main.cpp %SRC_PATH%\Logger.cpp

if %errorlevel% neq 0 (
    echo Build failed.
    exit /b %errorlevel%
)

echo Build succeeded.
