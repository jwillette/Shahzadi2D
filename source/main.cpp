#if defined(_WIN32) || (_WIN64)

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"

#include <direct.h>
#define getcwd _getcwd

#endif


#if defined(__APPLE__)

#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include "SDL2_mixer/SDL_mixer.h"

#include <unistd.h>

#endif


#include <stdio.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;





int main(int argc, char* argv[])
{
	srand(time(NULL));

#if defined(_WIN32) || (_WIN64)

	string cwd(getcwd(NULL, 0));

	string images_dir = cwd + "\\HealBreaker\\images\\";

	string audio_dir = cwd + "\\HealBreaker\\audio\\";

#endif


#if defined(__APPLE__)

	string cwd(getcwd(NULL, 0));

	string images_dir = cwd + "/HealBreaker/images/";

	string audio_dir = cwd + "/HealBreaker/audio/";

#endif



	SDL_Window *window;

	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("An SDL2 window", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, 1024, 768, SDL_WINDOW_OPENGL);

	if (window == NULL)
	{
		printf("Could not create window: %s\n", SDL_GetError());
		return 1;
	}



	SDL_Renderer *renderer = NULL;

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_Delay(3000);

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
