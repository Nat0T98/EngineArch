#include "Vector2.h"
#include <cmath>


const Vector2 Vector2::Zero(0, 0);

Vector2::Vector2()
{
	x = 0;
	y = 0;
}


Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

#pragma region Operators
Vector2 Vector2::operator+(const Vector2& other) const
{
	return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::operator-(const Vector2& other) const
{
	return Vector2(x - other.x, y - other.y);
}

Vector2 Vector2::operator*(const Vector2& other) const
{
	return Vector2(x * other.x, y * other.y);
}

Vector2 Vector2::operator/(const Vector2& other) const
{
	if (other.x != 0 && other.y != 0)
	{
		return Vector2(x / other.x, y / other.y);
	}
	else
	{
		return Vector2::Zero;
	}
}

Vector2 Vector2::operator/(float scalar) const
{
	if (scalar != 0)
	{
		return Vector2(x / scalar, y / scalar);
	}
	else
	{
		return Vector2::Zero;
	}
}
Vector2 Vector2::operator*(float scalar) const
{
	if (scalar != 0)
	{
		return Vector2(x * scalar, y * scalar);
	}
	else
	{
		return Vector2::Zero;
	}
}
#pragma endregion


Vector2 Vector2::Destination(Vector2 pos, Vector2 dest, float maxDistDelta)
{
	Vector2 toDest = dest - pos;

	float distance = toDest.Magnitude();

	if (distance <= maxDistDelta || distance == 0.0f)
	{
		return dest;
	}
	else
	{
		Vector2 direction = toDest / distance;
		return pos + direction * maxDistDelta;
	}
}

float Vector2::DistBetween(const Vector2& a, const Vector2& b)
{
	float dx = b.x - a.x;
	float dy = b.y - a.y;
	return std::sqrt(dx * dx + dy * dy);
}

float Vector2::Magnitude()
{
	return sqrt(x * x + y * y);
}
