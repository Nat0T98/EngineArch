#include "CollisionManager.h"

CollisionManager * CollisionManager::Cm_Instance = nullptr;

/// <summary>
/// Box Collision Bool, This will check the bounds of two colliders, if there is an overlap bool will be returned as true
/// </summary>
/// <param name="Square1"></param>
/// <param name="Square2"></param>
/// <returns></returns>
bool CollisionManager::BoxVsBox(Collider* Square1, Collider* Square2)
{
	if (Square1->x == nullptr || Square1->y == nullptr || Square1->width == nullptr || Square1->height == nullptr)
	{
		return false;
	}

	//Box Collider 1 bounds
	float MinX1 = *Square1->x;
	float MaxX1 = *Square1->x + *Square1->width;
	float MinY1 = *Square1->y;
	float MaxY1 = *Square1->y + *Square1->height;

	//Box Collider 2 bounds
	float MinX2 = *Square2->x;
	float MaxX2 = *Square2->x + *Square2->width;
	float MinY2 = *Square2->y;
	float MaxY2 = *Square2->y + *Square2->height;


	//Returning collider bounds against eachother
	return MaxX1 > MinX2 && MinX1 < MaxX2 && MaxY1 > MinY2 && MinY1 < MaxY2;
}

/// <summary>
/// Main collision detection function. Iterate through list of colliders if "BoxVsBox" bool returns true callback function will be called.
/// </summary>
void CollisionManager::CollisionDetection()
{
	for (auto i = ColliderHandler::Instance()->colliders.begin(); i != ColliderHandler::Instance()->colliders.end(); ++i)
	{
		for (auto j = std::next(i, 1); j != ColliderHandler::Instance()->colliders.end(); ++j)
		{
			Collider* box1 = *i;
			Collider* box2 = *j;
			
			if (box1 == nullptr || box2 == nullptr)
			{
				continue;
			}
			if (BoxVsBox(box1, box2))
			{
				//Callback to collider where appropriate object response will be called
				box1->callback(); 
				box2->callback();
			}			
		}
	}
}
