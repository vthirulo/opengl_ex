
#pragma once

#include "SDL3/SDL.h"

class WindowManager
{
public:
	WindowManager(const int width, const int height);

	~WindowManager();

	void ExecuteTheLoop();

private:
	SDL_Window* window;
	SDL_GLContext gl_context;

	uint16_t app_state;
};