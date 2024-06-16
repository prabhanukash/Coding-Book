# Makefile for building the project

CXX = g++
CXXFLAGS = -Iinclude

SRC = src/main.cpp src/Logger.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = my_program

all: $(TARGET)

$(TARGET): $(OBJ)
    $(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

clean:
    rm -f $(OBJ) $(TARGET)
