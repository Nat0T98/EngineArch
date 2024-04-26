#include <iostream>
#include "GameManager.h"
#include "SDL.h"

bool Initialise()
{
	if (SDL_InitSubSystem(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "Failed to initialise" << std::endl;
		return true;
	}
}

int main(int argc, char* argv[])
{
	if (Initialise())
	{
		std::cout << "Application Failed to Open" << std::endl;
		return -1;
	}

	GameManager::GM_Instance()->Play();

	return 0; 
}