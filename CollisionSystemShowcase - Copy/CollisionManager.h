#pragma once
#include <iostream>
#include "Collider.h"
#include "ColliderHandler.h"

class CollisionManager   
{
public:
	static CollisionManager* instance() { return Cm_Instance != nullptr ? Cm_Instance : Cm_Instance = new CollisionManager(); }

	static bool BoxVsBox(Collider* box1, Collider* box2);  		
	void CollisionDetection();
	
private:
	static CollisionManager* Cm_Instance;	
};

