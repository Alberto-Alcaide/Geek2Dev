#include <iostream> 


class Engine2D
{
private:
    double dt = 0;
    int last_frame_time = 0; // ms
    bool isGameRunning = 0;

public:

    Engine2D(int width, int height);
    ~Engine2D();

    Mouse* mouse;
    Keyboard keyboard;


}