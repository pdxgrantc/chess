# TODO remake make file with build rules for each file so they get recompiled upon a save

# Directories
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj
BIN_DIR = $(BUILD_DIR)/bin

# Toolchain
CXX = g++
RM = rm -f
RMDIR = rm -rf

# Files
TARGET = $(BIN_DIR)/chess

SOURCES = main.cpp

OBJECT_NAMES = $(SOURCES:.cpp=.o)
OBJECTS = $(patsubst %,$(OBJ_DIR)/%,$(OBJECT_NAMES))

# Flags
WFLAGS = #-Wall -Wextra -Werror -Wshadow
CXXFLAGS = $(WFLAGS) -Og -g -std=c++17
LDFLAGS =

# Build
.PHONY: all clean run mrun val

all: $(TARGET)

# Linking
$(TARGET): $(OBJECTS)
	@mkdir -p $(dir $@)
	$(CXX) $(LDFLAGS) $^ -o $@

# Compiling
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

mrun:
	clear
	$(MAKE) clean
	$(MAKE)
	./$(TARGET)

val:
	clear
	$(MAKE) clean
	$(MAKE)
	valgrind ./$(TARGET)

clean:
	$(RMDIR) $(BUILD_DIR)