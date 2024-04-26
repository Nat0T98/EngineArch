#pragma once
#include <functional>
#include <list>
class Collider
{
public:
// Paramaters needed to assign a collider to the object with the correct sizing.
// This is designed for square objects so does not act as smoothly for circle objects.
// The call back function will be appropriate for each object to showcase how this can work with differing objects


	Collider();
	virtual ~Collider();
	std::function<void()> callback;

	
	Collider(float& x, float& y, float& width, float& height, std::function<void()> callback);

	
	float* width;
	float* height;
	float* x;
	float* y;
	
};

