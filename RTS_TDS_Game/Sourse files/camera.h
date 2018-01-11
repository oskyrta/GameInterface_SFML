#pragma once
/////////////////////////////////////////////////
// Include
#include <SFML\Graphics.hpp>
#include <boost\property_tree\ptree.hpp>
#include "tools\vec2.h"

/////////////////////////////////////////////////
// Class Camera
class Camera
{
public:
	Camera();
	Camera(int width, int height);
	~Camera();

	void setPosition(Vec2 position);
	Vec2 getPosition() { return m_position; };

	void setOnScreenPosition(Vec2 position) { m_sprite.setPosition(position.getSFVector()); };
	Vec2 getOnScreenPosition() { return m_sprite.getPosition(); };

	sf::Sprite& getSprite();

	void setBackgroundColor(sf::Color color) { m_backgoundColor = color; };
	sf::Color getBackgoundColor() { return m_backgoundColor; }

	Vec2 getSize() { return m_size; };

	sf::RenderTexture* getRenderWindow() { return m_renderTexture; };

	void clearTexture() { m_renderTexture->clear(m_backgoundColor); }

private:
	Vec2 m_position;
	Vec2 m_onScreenPosition;
	Vec2 m_size;

	sf::Color m_backgoundColor;
	sf::View m_view;
	sf::Sprite m_sprite;
	sf::RenderTexture* m_renderTexture;
};