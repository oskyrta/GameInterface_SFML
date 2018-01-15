#pragma once
/////////////////////////////////////////////////
// Include
#include "uiObject.h"
#include <SFML\Graphics.hpp>

/////////////////////////////////////////////////
// Class GUISprite
class UISprite : public virtual UIObject
{
public:
	UISprite();
	~UISprite();

	void render();

	void initialize(std::string spriteName);

	void setRect(sf::IntRect rect) { m_rect = rect; m_sprite->setTextureRect(rect); };
	void setScale(float scale) { m_sprite->setScale(scale, scale); };
	void setSpriteName(std::string name) { m_spriteName = name; }

protected:
	std::string m_spriteName;

	sf::Sprite* m_sprite;
	sf::IntRect m_rect;
	int m_spriteSize;
};