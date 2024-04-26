#pragma once
#include "GameObject.h"
#include "Collider.h"
#include "ColliderHandler.h"

class Square : public GameObject
{
public:
	Square(Obj_Paramaters params);	
	virtual void Draw() override;	
	Collider* collider = nullptr; 
private:
	float width = 40;
	float height = 40;	
};

