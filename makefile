## VARIABLES HERE ##
SRC_DIR		:= src
BUILD_DIR	:= build
OBJ_DIR		:= $(BUILD_DIR)/obj
APP_DIR		:= $(BUILD_DIR)/bin
LIB_DIR		:= lib
INCLUDE_DIR	:= include

C			:= g++
CFLAGS		:= -pedantic-errors -Wall -Wextra
LDFLAGS		:= -L$(LIB_DIR)
INCLUDE		:= -isysteminclude -I$(INCLUDE_DIR)

SRC			:= $(wildcard src*/*.cpp)
OBJECTS 	+= $(SRC:%.cpp=$(OBJ_DIR)/%.o)

TARGET		:= App.exe

## COMPILATION HERE ##
all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	@win-mkdir.bat $(@D)
	$(C) $(CFLAGS) $(INCLUDE) -o $@ -c $<

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@win-mkdir.bat $(@D)
	$(C) $(CFLAGS) $(INCLUDE) $(OBJECTS) -o $(APP_DIR)/$(TARGET) $(LDFLAGS) 

build:
	@win-mkdir.bat $(BUILD_DIR)
	@win-mkdir.bat $(APP_DIR)
	@win-mkdir.bat $(OBJ_DIR)

release: C       += -mwindows
release: all

clean:
	./win-rmdir.bat $(OBJ_DIR)/*
	rm $(APP_DIR)/$(TARGET)
