#pragma once
#include "GameObject.h"
#include "Collider.h"
#include <random>
#include "ColliderHandler.h"
struct CircleParameters
{
	int32_t radius;
	CircleParameters(int32_t radius);
};

class Circle :public GameObject
{
public:
	Circle(Obj_Paramaters params, CircleParameters param);
	Collider* collider = nullptr;
	virtual void Draw() override;
	float radius;
	int dx;
	int dy;

	int x = pos.x + dx;
	int y = pos.y + dy;
};


