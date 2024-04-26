#include "GameManager.h"
#include "Square.h"
#include "Circle.h"

GameManager* GameManager::gm_instance = nullptr;


void GameManager::Play()
{
	if (Initialise())
	{
		std::cout << "Application failed to initialise. Quitting... " << std::endl;
		return;
	}	

	//Initial Texture
	SDL_Texture* Texture = SDL_CreateTexture(g_sdlRenderer, SDL_PIXELFORMAT_ARGB32, SDL_TEXTUREACCESS_TARGET, 64, 64);
	SDL_SetRenderTarget(g_sdlRenderer, Texture);
	SDL_SetRenderDrawColor(g_sdlRenderer, 255, 0, 255, 255);
	SDL_RenderClear(g_sdlRenderer);
	SDL_SetRenderTarget(g_sdlRenderer, NULL);

	//Texture that shape will change to on collision
	SDL_Texture* Texture2 = SDL_CreateTexture(g_sdlRenderer, SDL_PIXELFORMAT_ARGB32, SDL_TEXTUREACCESS_TARGET, 64, 64);
	SDL_SetRenderTarget(g_sdlRenderer, Texture2);
	SDL_SetRenderDrawColor(g_sdlRenderer, 30, 128, 87, 200);
	SDL_RenderClear(g_sdlRenderer);
	SDL_SetRenderTarget(g_sdlRenderer, NULL);
	 
	//Objects instantiated here
	CreateShapes(ObjectShape::SquareObj, 3,g_sdlRenderer, Texture,Texture2);
	CreateShapes(ObjectShape::CircleObj, 2, g_sdlRenderer, Texture, Texture2);
	
	keepRunning = true;	
	while (keepRunning)
	{
		SDL_SetRenderDrawColor(g_sdlRenderer, 255, 255, 50, 255); //Background colour
		SDL_RenderClear(g_sdlRenderer);
		Update();
		SDL_RenderPresent(g_sdlRenderer);

		SDL_Event sdlEvent;
		while (SDL_PollEvent(&sdlEvent))
		{
			switch (sdlEvent.type)
			{
			case SDL_QUIT:
				keepRunning = false;
				break;

			case SDL_KEYDOWN:
				if (sdlEvent.key.keysym.sym == SDLK_ESCAPE) //Quit
				{
					keepRunning = false;
				}
			}
		}
	}

#pragma region CleanUp
SDL_DestroyTexture(Texture);
	SDL_DestroyTexture(Texture2);
	CleanUp();
	#pragma endregion
	
}

bool GameManager::Initialise()
{
	int iwindowflag = SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_FULLSCREEN_DESKTOP;
	g_sdlWindow = SDL_CreateWindow( "Nathan Jowett Collision System Showcase", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 500, NULL);

	if (g_sdlWindow == nullptr)
	{
		std::cout << "Failed to create window. SDL error: " << SDL_GetError() << std::endl;
		return true;
	}
	g_sdlRenderer = SDL_CreateRenderer(g_sdlWindow, -1, SDL_RENDERER_ACCELERATED);
	if (g_sdlRenderer == nullptr)
	{
		std::cout << "Failed to create renderer. SDL error: " << SDL_GetError() << std::endl;
		return true;
	}
	return false;
}

void GameManager::CleanUp()
{
	SDL_DestroyRenderer(g_sdlRenderer);
	SDL_DestroyWindow(g_sdlWindow);
	SDL_Quit();
	ColliderHandler::Instance()->CleanUp();
}

#pragma region DeltaTime Functions
void GameManager::DeltaTime()
{
	UpdateDeltaTime();
	timeScale = 1;
}

float GameManager::GetDeltaTime() const
{
	return deltaTime * timeScale;
}

float GameManager::UpdateDeltaTime()
{
	deltaTime = (SDL_GetTicks() - (float)(previousTicks)) / 1000;
	previousTicks = SDL_GetTicks();
	return deltaTime;
}
#pragma endregion

SDL_Renderer* GameManager::GetRenderer()
{
	return g_sdlRenderer;
}


void GameManager::Update() //Game Updates Every Tick
{
	timeScale = 1;
	UpdateDeltaTime();
	std::list<GameObject*>::iterator i;
	i = this->shapes.begin();

	//Iterates through each game object
	for (std::list<GameObject*>::const_iterator i = this->shapes.begin(), end = this->shapes.end();i!=end;++i)
	{
		(*i)->UpdateShapes();		
	}	
	
	ColliderHandler::Instance()->CollisionEvent();	
}

/// <summary>
/// For loop that iterates through list of game objects.
/// Quantities for each are set in play function.
/// For each amount of shape set a game object of that type will be instantiated at runtime.
/// </summary>
/// <param name="shape"></param>
/// <param name="amount"></param>
/// <param name="renderer"></param>
/// <param name="texture1"></param>
/// <param name="texture2"></param>
void GameManager::CreateShapes(ObjectShape shape, int amount, SDL_Renderer* renderer, SDL_Texture* texture1, SDL_Texture* texture2)
{
	
	if (shape == ObjectShape::SquareObj)
	{
		for (int i = 0; i < amount; ++i)
		{
			Obj_Paramaters Paramaters(texture1, texture2, renderer, shape);
			Square* square = new Square(Paramaters);
			shapes.push_back(square);
		}

	}
	else if (shape == CircleObj)
	{
		for (int i = 0; i < amount; ++i)
		{
			Obj_Paramaters Paramaters(texture1, texture2, renderer, shape);
			CircleParameters CircleParam(25);
			Circle* circle = new Circle(Paramaters, CircleParam);
			shapes.push_back(circle);
		}
	}
}

