#pragma once
#include <iostream>
#include "SDL.h"
#include "GameObject.h"
#include <list>
#include <random>

class GameObject;
enum ObjectShape;

class GameManager
{
public:
	static GameManager* GM_Instance() { return gm_instance != nullptr ? gm_instance : gm_instance = new GameManager(); }
	void Play();
	bool Initialise();
	void CleanUp();
	void DeltaTime();
	float GetDeltaTime()const;
	float UpdateDeltaTime();
	
	SDL_Renderer* GetRenderer();

private:
	
	bool keepRunning;
	static GameManager* gm_instance;

	std::list<GameObject*> shapes;

	SDL_Window* g_sdlWindow;
	SDL_Renderer* g_sdlRenderer;

	void Update();
	void CreateShapes(ObjectShape shape, int amount, SDL_Renderer* renderer, SDL_Texture* Texture1 ,SDL_Texture* Texture2);
	
	float deltaTime;
	float timeScale;
	Uint32 previousTicks;
};