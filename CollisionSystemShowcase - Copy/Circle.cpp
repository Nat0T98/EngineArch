#include "Circle.h"

//Instantiation of object using object paramaters. For every circle drawn a collider will be assigned and added to the list
//Here we will also bind the appropriate call back response for circle collision
Circle::Circle(Obj_Paramaters paramaters, CircleParameters Cparams)
{
	Texture1 = paramaters.texture;
	Texture2 = paramaters.texture2;
	Renderer = paramaters.renderer;
	ShapeObj = paramaters.type;
	radius = Cparams.radius;

	collider = new Collider(pos.x, pos.y, radius, radius, std::bind(&GameObject::ChangeCircleColour, this));//Use radius here instead of Height/Width params
	ColliderHandler::Instance()->AddCollider(collider);
	SetSpawnPoint();
}

//Overload of draw function to draw a circle shape
void Circle::Draw()
{	
	//Circle doesnt seem to play well with texture setting so manually setting a draw colour, this colour will be changed on collision
	SDL_SetRenderDrawColor(Renderer, Colour.r, Colour.g, Colour.b,Colour.a );
	for (int w = 0; w < radius * 2; ++w)
	{		
		for (int h = 0; h < radius * 2; ++h)
		{
			dx = radius - w;
			dy = radius - h;
			if ((dx * dx + dy * dy) <= (radius * radius))
			{				
				SDL_RenderDrawPoint(Renderer, pos.x + dx, pos.y + dy);				
			}
		}
	}
} 


CircleParameters::CircleParameters(int32_t radius)
{
	this->radius = radius;
}