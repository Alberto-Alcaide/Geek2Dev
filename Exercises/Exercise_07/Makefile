OBJS = hide_test.cpp
OBJ_NAME = test.exe
CPP = g++
ENGINE_SOURCE_FILES = ./../../Engine/*.cpp 
ENGINE_INCLUDE_PATHS = -I./../../Engine/ -I./../../libs/entt/src -I./../../Engine/ECS/Components -I./../../Engine/ECS/Systems

INCLUDE_PATHS = -IC:\mingw_dev_lib\include
LIBRARY_PATHS = -LC:\mingw_dev_lib\lib
COMPILER_FLAGS = -std=c++17 -Wall
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2

build:
	$(CPP) $(OBJS) $(ENGINE_SOURCE_FILES) $(ENGINE_INCLUDE_PATHS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
