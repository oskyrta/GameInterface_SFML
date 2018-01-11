//////////////////////////////////////////////
// Include
#include "uiObject.h"
#include <SFML\Graphics.hpp>
#include "camera.h"
#include "tools/utils.h"
#include "dataManager.h"
#include "inputController.h"

//////////////////////////////////////////////
// Class GUIObject
UIObject::UIObject()
{
	m_dataManager = DataManager::instance();
	m_inputController = InputController::instance();

	m_name = "";
	m_camera = 0;
}

UIObject::~UIObject()
{
	m_tree.put(m_name + ".x", m_pos.x);
	m_tree.put(m_name + ".y", m_pos.y);
}

void UIObject::update()
{
	m_mouseOnObject = false;

	if (m_inputController->mouseOnWindow())
	{
		Vec2 mousePosition = m_inputController->getMousePosition() - m_camera->getPosition();

		// Check intersect with mouse
		if (abs(mousePosition.x - m_pos.x) <= m_size.x && abs(mousePosition.y - m_pos.y) <= m_size.y)
			m_mouseOnObject = true;
	}
}