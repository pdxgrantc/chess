# Directories
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj
BIN_DIR = $(BUILD_DIR)/bin

# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -g -Og -MMD -MP

# Target
TARGET = $(BIN_DIR)/chess

# Source files
SOURCES = \
	main.cpp \
	board.cpp \
	game.cpp \
	piece.cpp

# Derived files
OBJECTS = $(addprefix $(OBJ_DIR)/,$(SOURCES:.cpp=.o))
DEPS = $(OBJECTS:.o=.d)

.PHONY: all clean run mrun val

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $^ -o $@

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

mrun: $(TARGET)
	@clear
	./$(TARGET)

val: $(TARGET)
	@clear
	valgrind ./$(TARGET)

clean:
	rm -rf $(BUILD_DIR)

-include $(DEPS)