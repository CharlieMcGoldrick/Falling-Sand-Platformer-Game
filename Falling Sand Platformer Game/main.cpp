// <iostream> allows you to output to the console
#include <iostream>
// Usually just SDL.h but we put the file in a folder to keep things tidy
#include "SDL2/SDL.h"


int main(int argc, char* args[]) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "Error: Couldn't initialize SDL video = " << SDL_GetError() << std::endl;
		return 1;
	}
	else {
		// Create the window
		SDL_Window* window = SDL_CreateWindow("Falling Sand Platformer Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 512, 512, 0);
		if (window == nullptr) {
		std::cout << "Error: Couldn't create window = " << SDL_GetError() << std::endl;
		return 1;
		}
		else {
			// Create a renderer for GPU accelerated drawing
			SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if (renderer == nullptr) {
				std::cout << "Error: Couldn't create renderer = " << SDL_GetError() << std::endl;
				return 1;
			}
			else {
				std::cout << "Success!" << std::endl;

				// Output the name of the render driver
				SDL_RendererInfo rendererInfo;
				SDL_GetRendererInfo(renderer, &rendererInfo);
				std::cout << "Renderer = " << rendererInfo.name << std::endl;

				SDL_Delay(3000);

				// Clean up
				SDL_DestroyRenderer(renderer);
			}
		}

		// Clean up
		SDL_DestroyWindow(window);
	}

	return 0;
}