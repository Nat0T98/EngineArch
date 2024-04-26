#pragma once
#include "SDL.h"
#include <iostream>
#include <string>
#include "GameManager.h"
#include "Vector2.h"
#include "ColliderHandler.h"
#include <cmath>


enum ObjectShape
{
	SquareObj,
	CircleObj
};

struct Obj_Paramaters 
{
	SDL_Texture* texture;
	SDL_Texture* texture2;
	SDL_Renderer* renderer;
	ObjectShape type;

	Obj_Paramaters(SDL_Texture* texture, SDL_Texture* Texture2, SDL_Renderer* renderer, ObjectShape objShape);
};

struct ObjColour
{
	Uint8 r;
	Uint8 g;
	Uint8 b;
	Uint8 a;
};

class GameObject
{
public:
	GameObject(ObjectShape objShape);
	GameObject(Obj_Paramaters params);
	GameObject();
	~GameObject();

	void UpdateShapes();
	void ChangeSqaureTexture();
	void ChangeCircleColour();
	
protected:
	
	virtual void Draw();
	void SetSpawnPoint();
	void ObjMovement(float deltaTime);

	SDL_Renderer* Renderer = nullptr;
	SDL_Texture* texture = nullptr;
	SDL_Texture* Texture1 = nullptr;
	SDL_Texture* Texture2 = nullptr;

	ObjectShape ShapeObj; 
	ObjColour Colour;

	int maxX = 600;
	int maxY = 500;

	int MaxBorderX = 560;
	int MaxBorderY = 460;
	int MinBorderX = 40;
	int MinBorderY = 40;

	float speed = 100;
	bool atDestination = true;
	bool textureActive = true;

	Vector2 pos;
	Vector2 destination;
	
};