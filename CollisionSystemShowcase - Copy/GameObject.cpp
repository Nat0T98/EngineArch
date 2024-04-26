#include "GameObject.h"

GameObject::GameObject(ObjectShape shape)
{
	ShapeObj = shape;	
}

GameObject::GameObject(Obj_Paramaters p)
{
	Texture1 = p.texture; 
	Texture2 = p.texture2;
	Renderer = p.renderer; 
	ShapeObj = p.type;
	texture = Texture1;
	
	SetSpawnPoint();
}

Obj_Paramaters::Obj_Paramaters(SDL_Texture* texture, SDL_Texture* Texture2, SDL_Renderer* renderer, ObjectShape type)
{
	this->texture = texture;
	this->texture2 = Texture2;
	this->renderer = renderer;
	this->type = type;
}

GameObject::GameObject()
{

}

GameObject::~GameObject()
{
	SDL_DestroyTexture(texture);
	SDL_DestroyTexture(Texture1);
	SDL_DestroyTexture(Texture2);
}

void GameObject::Draw() 
{
	//Logic to draw object classes
}

void GameObject::UpdateShapes()
{	
	Draw();
	ObjMovement(GameManager::GM_Instance()->GetDeltaTime());
}

/// <summary>
/// On Collision if object is square call back function will call this function to output a secondary texture whilst object is colliding
/// </summary>
void GameObject::ChangeSqaureTexture() 
{
	std::cout << "Square Object Collision Callback Called" << std::endl;
	if (textureActive == true)
	{
		texture = Texture2;
		Texture2 = Texture1;
		textureActive = false;
	}
	else
	{
		Texture2 = texture;
		texture = Texture1;
		textureActive = true;
	}
}

/// <summary>
/// On collision if object is a circle the callback function will call this function to output colour changing whilst the object is colliding
/// </summary>
void GameObject::ChangeCircleColour()
{
	std::cout << "Circle Object Collision Callback Called" << std::endl;

	Colour.r = rand() % 255 + 1;
	Colour.g = rand() % 255 + 1;
	Colour.b = rand() % 255 + 1;
	Colour.a = rand() % 255 + 1;
}

void GameObject::SetSpawnPoint()
{	
	int randX = rand() % maxX + 1;
	int randY = rand() % maxY + 1;

	pos.x = randX;
	pos.y = randY; 

}

/// <summary>
/// Chooses a random X and Y pos for the object to set as destination,if object is within range of destination a new destination is set
/// </summary>
/// <param name="deltaTime"></param>
void GameObject::ObjMovement(float deltaTime) 
{
	static const float DestinationRange = 1.0f;
	
	pos = Vector2::Destination(pos, destination, speed * deltaTime);
	
	if (Vector2::DistBetween(pos, destination) < DestinationRange)
	{
		atDestination = true;
	}	

	if (atDestination) 
	{
		int randX = rand() % maxX + 1;
		int randY = rand() % maxY + 1;
		destination = Vector2(randX, randY);

		atDestination = false;
	}
	
	if (pos.x > MaxBorderX || pos.x < MinBorderX || pos.y > MaxBorderY || pos.y < MinBorderY) //Object Moveable Area logic
	{
		atDestination = true;	
	}

}



