#include "glad/gl.h"

#include "window.hpp"
#include "graphics.hpp"
#include "shader_handler.hpp"

#include <math.h>

WindowManager::WindowManager(const int width, const int height) :
	window { nullptr }, gl_context { nullptr }, app_state { 0 }
{
	if (!SDL_Init(SDL_INIT_VIDEO))
	{
		SDL_LogError(SDL_LOG_PRIORITY_ERROR, "%s", SDL_GetError());
		return;
	}

	SDL_Log("SDL Initialized");

	window = SDL_CreateWindow("OpenGL Application", width, height, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	if (window == NULL)
	{
		SDL_LogError(SDL_LOG_PRIORITY_ERROR, "%s", SDL_GetError());
		return;
	}

	SDL_Log("OpenGL Window Created");

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);


	this->gl_context = SDL_GL_CreateContext(window);

	if (gl_context == NULL)
	{
		SDL_LogError(SDL_LOG_PRIORITY_ERROR, "%s", SDL_GetError());
		return;
	}

	if(!SDL_GL_MakeCurrent(window, gl_context))
	{
		SDL_LogError(SDL_LOG_PRIORITY_ERROR, "%s", SDL_GetError());
		return;
	}

	int version = gladLoadGL((GLADloadfunc)SDL_GL_GetProcAddress);
	
	if (version == 0) {
		SDL_LogError(SDL_LOG_PRIORITY_ERROR, "Failed to load OpenGL Context");
        return;
    }

    // Successfully loaded OpenGL
    SDL_Log("Loaded OpenGL %d.%d\n", GLAD_VERSION_MAJOR(version), GLAD_VERSION_MINOR(version));
	
	this->app_state = 1;
	
}

WindowManager::~WindowManager()
{
	SDL_DestroyWindow(window);
	window = nullptr;

	SDL_Log("Window Destroyed !");

	SDL_Quit();
	
	SDL_Log("SDL Quit() called !");

}

void WindowManager::ExecuteTheLoop()
{
	SDL_Event evnt{};

	Graphics graphics_inst{};

	while (this->app_state)
	{
		while (SDL_PollEvent(&evnt))
		{
			if (evnt.type == SDL_EVENT_QUIT || evnt.key.scancode == SDL_SCANCODE_ESCAPE)
			{
				app_state = 0;
			}
			if (evnt.type == SDL_EVENT_WINDOW_RESIZED)
			{
				int w{}, h{};
				SDL_GetWindowSize(window, &w, &h);
				SDL_Log("Window has been resized to %dx%d", w, h);
				glViewport(0, 0, w, h);
			}
		}
		
		graphics_inst.Display();
		SDL_GL_SwapWindow(window);
	}
}

