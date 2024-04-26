#include "ColliderHandler.h"

ColliderHandler* ColliderHandler::ch_instance = nullptr;

//Will be called on instantiation of game objects to add colliders to the list that will be used in the collision detection
void ColliderHandler::AddCollider(Collider* collider)
{
	colliders.push_back(collider);
}

// A reference back to the Collision Detection so that it can check constantly
void ColliderHandler::CollisionEvent()
{	
	CollisionManager::instance()->CollisionDetection();
	
}

//Clears list of colliders
void ColliderHandler::CleanUp()
{
	for (auto i = colliders.begin(); i != colliders.end(); ++i)
	{
		delete* i;
		*i = nullptr;
	}
}



