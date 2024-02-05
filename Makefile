# Compiler settings - Can change depending on the compiler you use
CXX=g++
CXXFLAGS=-Wall -g -Iinclude -std=c++17  # Added -std=c++17 here
# Project files
SRCDIR=src
INCDIR=include
BUILDDIR=build
TARGET=bin/program

# Find all cpp files in the src directory
SOURCES=$(shell find $(SRCDIR) -type f -name *.cpp)
# Replace the src directory with the build directory and change the file extension from .cpp to .o
OBJECTS=$(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SOURCES))

# Default make
all: $(TARGET)

# Link the target executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile the source files into object files
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up the build
clean:
	rm -rf $(BUILDDIR) $(TARGET)

.PHONY: all clean
