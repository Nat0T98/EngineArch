#include "Square.h"

//Instantiation of object using object paramaters. For every square drawn a collider will be assigned and added to the list
//Here we will also bind the appropriate call back response for square collision
Square::Square(Obj_Paramaters params) :GameObject(params)
{
	Texture1 = params.texture;
	Texture2 = params.texture2;
	Renderer = params.renderer;
	ShapeObj = params.type;
	collider = new Collider(pos.x, pos.y, width, height,std::bind(&GameObject::ChangeSqaureTexture, this));
	ColliderHandler::Instance()->AddCollider(collider);
}

//Overload of draw function to draw a square shape
void Square::Draw()
{	
	Vector2 Centre = pos + Vector2(width / 2, height / 2);

	SDL_Rect dstRect{ Centre.x,Centre.y,width,height };
	SDL_RendererFlip flip = SDL_FLIP_NONE;
	float rot = 0;
	SDL_RenderCopyEx(GameManager::GM_Instance()->GetRenderer(), texture, NULL, &dstRect, rot, NULL, flip);
}

