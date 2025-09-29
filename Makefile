# Makefile for the library project
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -I./Ressources
SRC_DIR = .
RES_DIR = ./Ressources
OBJ_DIR = obj

# List all source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(RES_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(filter $(SRC_DIR)/%.cpp,$(SRCS))) \
	$(patsubst $(RES_DIR)/%.cpp,$(OBJ_DIR)/Ressources/%.o,$(filter $(RES_DIR)/*.cpp,$(SRCS)))

TARGET = mon_programme

all: $(OBJ_DIR) $(TARGET)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compile main sources
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile Ressources sources (crée le sous-dossier obj/Ressources si besoin)
$(OBJ_DIR)/Ressources/%.o: $(RES_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)/Ressources
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: all clean
