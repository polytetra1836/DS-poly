# Makefile for Chicken project

# Compiler
CXX = g++

# Target executable
TARGET = main

# Source files
SRCS = main.cpp

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Build the executable
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Clean the build files
clean:
	rm -f $(TARGET)
