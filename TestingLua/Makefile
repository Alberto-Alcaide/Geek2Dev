OBJS = scriptLua.cpp  
ENGINE = C:\Geek2Dev\Engine/Color.cpp C:\Geek2Dev\Engine/Engine2D.cpp C:\Geek2Dev\Engine/Graphics.cpp C:\Geek2Dev\Engine/Log.cpp C:\Geek2Dev\Engine/Vec2D.cpp C:\Geek2Dev\Engine\Collision/Collision.cpp 
OBJ_NAME = test.exe
CPP = g++
INCLUDE_PATHS = -IC:\mingw_dev_lib\include -IC:\mingw_dev_lib\bin -IC:\Geek2Dev\Engine -IC:\Geek2Dev\libs\entt\src -IC:\Geek2Dev\Engine\ECS\Components -IC:\Geek2Dev\Engine\ECS\Systems -IC:\Geek2Dev\Engine\Shape -IC:\Geek2Dev\Engine\Events -IC:\Geek2Dev\Engine\Collision
LIBRARY_PATHS = -LC:\mingw_dev_lib\lib
COMPILER_FLAGS = -std=c++17 -Wall
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -llua53

build:
		$(CPP) $(ENGINE) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)