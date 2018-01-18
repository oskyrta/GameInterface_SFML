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
	m_tree->put("x", m_relativePos.x);
	m_tree->put("y", m_relativePos.y);
}

void UIObject::initialize(PropertyTree* tree)
{
	m_tree = tree;

	m_relativePos.x = m_tree->get<float>("x");
	m_relativePos.y = m_tree->get<float>("y");

	m_pos.x = (int)(m_relativePos.x * m_camera->getHalfSize().x);
	m_pos.y = (int)(m_relativePos.y * m_camera->getHalfSize().y);
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