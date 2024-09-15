# Makefile for hello project

# Compiler
CXX = g++

# Target executable
TARGET = hello

# Source files
SRCS = hello.cpp

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Build the executable
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Clean the build files
clean:
	rm -f $(TARGET)
