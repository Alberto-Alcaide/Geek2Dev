#ifndef keyboardH
#define keyboardH

struct Keyboard
{
    bool upKeyPressed = false;
    bool downKeyPressed = false;
    bool leftKeyPressed = false;
    bool rightKeyPressed = false;

    Keyboard() = default;
    ~Keyboard() = default;
};

#endif