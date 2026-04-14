

#include "SDL3/SDL_main.h"

#include "window.hpp"

int main(int argc, char *argv[])
{

    WindowManager window{ 1280, 720 };

    window.ExecuteTheLoop();

    return 0;
}
