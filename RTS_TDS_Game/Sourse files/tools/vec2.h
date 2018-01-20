#pragma once
/////////////////////////////////////////////////
// Include
#include <SFML\Graphics.hpp>

/////////////////////////////////////////////////
// Class Vec2
class Vec2
{
public:
	Vec2(float X = 0, float Y = 0);
	Vec2(sf::Vector2f vec);

	Vec2 operator+(const Vec2& a);
	Vec2 operator-(const Vec2& a);
	Vec2 operator+=(const Vec2& a);
	Vec2 operator*(const float& a);
	Vec2 operator*(const Vec2& a);
	Vec2 operator/(const float& a);
	Vec2 operator/(const Vec2& a);
	bool operator==(const Vec2& a);

	sf::Vector2f getSFVector();

	Vec2 normalize();
	Vec2 magnitude(float ragius);
	Vec2 getInt() { return Vec2((int)x, (int)y); };
	float length();

	float x;
	float y;
};

