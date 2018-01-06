//////////////////////////////////////////////
// Include
#include "uiObject.h"
#include <SFML\Graphics.hpp>
#include "camera.h"
#include "tools/utils.h"
#include "dataManager.h"

//////////////////////////////////////////////
// Class GUIObject
UIObject::UIObject()
{
	m_dataManager = DataManager::instance();

	m_name = "";
	m_camera = 0;
}

UIObject::~UIObject()
{
	//std::cout << m_tag + " " << m_pos.x << " " << m_pos.y << std::endl;
	m_tree.put(m_name + ".x", m_pos.x);
	m_tree.put(m_name + ".y", m_pos.y);
}

void UIObject::update()
{
	m_mouseOnObject = false;

	// Get mouse position on screen
	sf::Vector2i mp = sf::Mouse::getPosition(*m_camera->getRenderWindow());
	// Calculate mouse position in world coordinate considering zoom
	sf::Vector2f worldPosition = m_camera->getRenderWindow()->mapPixelToCoords(mp);
	// Calculate position on game interface
	Vec2 mousePosition = Vec2(worldPosition.x, worldPosition.y) - m_camera->getPosition();

	// Check intersect with mouse
	if (abs(mousePosition.x - m_pos.x) <= m_size.x && abs(mousePosition.y - m_pos.y) <= m_size.y) m_mouseOnObject = true;
}