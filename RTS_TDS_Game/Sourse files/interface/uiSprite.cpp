////////////////////////////////////////////////
// Include
#include "uiSprite.h"
#include "camera.h"


////////////////////////////////////////////////
// Class UISprite
UISprite::UISprite()
{
	// Initialize sprite
	m_spriteSize = 1;
}

UISprite::~UISprite()
{
	if (m_sprite)
		delete m_sprite;
}

void UISprite::initialize(std::string spriteName)
{
//	m_sprite = new sf::Sprite();
//	m_sprite->setTexture(*g_atlas00);
//	m_sprite->setTextureRect(sf::IntRect());
//
//	// Get sprite parameters from data
//	sf::IntRect rect;
//	rect.left = settingsManager.p_spriteParameters->get<int>(spriteName + ".x");
//	rect.top = settingsManager.p_spriteParameters->get<int>(spriteName + ".y");
//	rect.width = settingsManager.p_spriteParameters->get<int>(spriteName + ".width");
//	rect.height = settingsManager.p_spriteParameters->get<int>(spriteName + ".height");
//	m_spriteSize = settingsManager.p_spriteParameters->get<int>(spriteName + ".size");
//
//	m_sprite->setTextureRect(rect);
//	m_rect = rect;
//	m_sprite->setScale(m_spriteSize, m_spriteSize);
}

void UISprite::render()
{
	if (m_rect.height != 0)
	{
		// Calculation top left point
		float x = (m_pos.x - m_sprite->getTextureRect().width / 2);
		float y = (m_pos.y - m_sprite->getTextureRect().height / 2);

		// Set position relative to the camera
		m_sprite->setPosition(roundf(x) + m_camera->getPosition().x, roundf(y) + m_camera->getPosition().y);

		m_camera->getRenderWindow()->draw(*m_sprite);
	}
}