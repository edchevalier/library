# Makefile for the library project
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -I./Ressources -I./mainClasses -I./Users
MAIN_DIR = .
MAIN_CLASSES_DIR = ./mainClasses
RES_DIR = ./Ressources
USERS_DIR = ./Users
OBJ_DIR = obj

# List all source files
SRCS = $(wildcard $(MAIN_DIR)/*.cpp) $(wildcard $(MAIN_CLASSES_DIR)/*.cpp) \
       $(wildcard $(RES_DIR)/*.cpp) $(wildcard $(USERS_DIR)/*.cpp)

OBJS = $(patsubst $(MAIN_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(filter $(MAIN_DIR)/%.cpp,$(SRCS))) \
       $(patsubst $(MAIN_CLASSES_DIR)/%.cpp,$(OBJ_DIR)/mainClasses/%.o,$(filter $(MAIN_CLASSES_DIR)/%.cpp,$(SRCS))) \
       $(patsubst $(RES_DIR)/%.cpp,$(OBJ_DIR)/Ressources/%.o,$(filter $(RES_DIR)/%.cpp,$(SRCS))) \
       $(patsubst $(USERS_DIR)/%.cpp,$(OBJ_DIR)/Users/%.o,$(filter $(USERS_DIR)/%.cpp,$(SRCS)))

TARGET = app

all: $(OBJ_DIR) $(TARGET)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR) $(OBJ_DIR)/mainClasses $(OBJ_DIR)/Ressources $(OBJ_DIR)/Users

# Compile main sources
$(OBJ_DIR)/%.o: $(MAIN_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile mainClasses sources
$(OBJ_DIR)/mainClasses/%.o: $(MAIN_CLASSES_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile Ressources sources
$(OBJ_DIR)/Ressources/%.o: $(RES_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile Users sources
$(OBJ_DIR)/Users/%.o: $(USERS_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: all clean
