OBJS = test.cpp Color.cpp
OBJ_NAME = test.exe
CPP = g++
INCLUDE_PATHS = -IC:\mingw_dev_lib\include -IC:\Geek2Dev\Engine
LIBRARY_PATHS = -LC:\mingw_dev_lib\lib
COMPILER_FLAGS = -std=c++17 -Wall
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2

build:
	$(CPP) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
