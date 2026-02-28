# Compiler
CXX = g++
# Compiler Flags
CXXFLAGS = -std=c++17 -Wall -Wextra -I./src

SRC_DIR = src
BUILD_DIR = build

# Find all .cpp files recursively
SRCS = $(shell find $(SRC_DIR) -name "*.cpp")
OBJS = $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

# Target executable name
TARGET = virtual_motor_controller

# Default rule: build program
all: $(TARGET)

# Build rule
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile each .cpp into a .o file inside build/
$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(TARGET)