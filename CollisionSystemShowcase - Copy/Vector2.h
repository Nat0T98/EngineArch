#pragma once
class Vector2
{
public:
	float x, y;
	
	Vector2();
	Vector2(float x, float y);

	Vector2 operator+(const Vector2& other) const;
	Vector2 operator-(const Vector2& other) const;
	Vector2 operator*(const Vector2& other) const;
	Vector2 operator/(const Vector2& other) const;
	Vector2 operator/(float scalar) const;
	Vector2 operator*(float scalar) const;
	
	static const Vector2 Zero;
	static Vector2 Destination(Vector2 current, Vector2 target, float maxDistDelta);	
	static float DistBetween(const Vector2& a, const Vector2& b);
	float Magnitude();
};

