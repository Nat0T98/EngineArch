#pragma once
#include <iostream>
#include <list>
#include "CollisionManager.h"
#include "Collider.h"
class ColliderHandler
{
public:
	static ColliderHandler* Instance() { return ch_instance != nullptr ? ch_instance : ch_instance = new ColliderHandler();}
	void AddCollider(Collider* collider);
	void CollisionEvent();
	void CleanUp();

	//Contains the list of colliders that have been created
	std::list<Collider*> colliders;


private:
	static ColliderHandler* ch_instance;	
};

