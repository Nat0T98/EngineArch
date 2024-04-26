#include "Collider.h"

Collider::Collider()
{

}

Collider::~Collider()
{

}
/// <summary>
/// Paramaters needed to assign a collider to the object with the correct sizing.
/// This is designed for square objects so does not act as smoothly for circle objects.
/// The call back function will be appropriate for each object to showcase how this can work with differing objects
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="width"></param>
/// <param name="height"></param>
/// <param name="callback"></param>
Collider::Collider(float& x, float& y, float& width, float& height, std::function<void()> callback)
{
	this->x = &x;
	this->y = &y;
	this->width = &width;
	this->height = &height;
	this->callback = callback;
}

