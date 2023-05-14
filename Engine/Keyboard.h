#ifndef keyboardH
#define keyboardH

struct Keyboard
{
    bool isUpPressed = false;
    bool isDownPressed = false;
    bool isLeftPressed = false;
    bool isRightPressed = false;

    Keyboard() = default;
    ~Keyboard() = default;
};

#endif