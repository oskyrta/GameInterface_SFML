////////////////////////////////////////////////
// Include
#include "interfaceWindow.h"

#include "camera.h"
#include "interface/uiButton.h"
#include "interface/uiText.h"
#include "interface/uiObject.h"
#include "interface/uiSprite.h"
#include "eventSystem/eventController.h"
#include "tools/utils.h"
#include "dataManager.h"

#include <boost\foreach.hpp>
#include <boost\property_tree\ptree.hpp>

#include <string>

typedef boost::property_tree::ptree PropertyTree ;

////////////////////////////////////////////////
// Extern
extern sf::Font* g_font;

////////////////////////////////////////////////
// Class InterfaceWindow
InterfaceWindow::InterfaceWindow()
{
	m_isActive = false;
	m_dataManager = DataManager::instance();

	// Clear buttons ans text lists
	for (int i = 0; i < 30; i++)
	{
		m_objectsList[i] = 0;
	}
}

InterfaceWindow::~InterfaceWindow()
{
	// Delete interface objects
	for (int i = 0; i < 30; i++)
	{
		if (m_objectsList[i] != 0)
		{
			delete m_objectsList[i];
			m_objectsList[i] = 0;
		}
	}
}

void InterfaceWindow::createButtons()
{
	PropertyTree buttons = m_dataManager->getInterfaceSettings()->get_child("Buttons");

	BOOST_FOREACH(auto &v, buttons)
	{
		
	}
}

void InterfaceWindow::createTexts()
{

}

void InterfaceWindow::createSprites()
{

}

void InterfaceWindow::initialize(std::string name)
{

}

void InterfaceWindow::update()
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition(*m_camera->getRenderWindow());
	sf::Vector2f worldPosition = m_camera->getRenderWindow()->mapPixelToCoords(mousePosition);

	for (int i = 0; i < 30; i++)
	{
		if (m_objectsList[i] != 0)
			m_objectsList[i]->update();
	}
	
	if (IsKeyDown(0x70) && m_eventController->getEventState(GameEvent_LeftButtonStay))
	{
		for (int i = 0; i < 30; i++)
		{
			if (m_objectsList[i] != 0 && m_objectsList[i]->getMouseOnObject() && m_eventController->getEventState(GameEvent_LeftButtonStay) )
			{
				// Calculate cursor position on window
				Vec2 windowCursorPosition = Vec2(round(worldPosition.x), round(worldPosition.y)) + m_camera->getPosition();
				m_objectsList[i]->setPosition(windowCursorPosition);

				break;
			}
		}
	}
}

void InterfaceWindow::render()
{
	for (int i = 0; i < 30; i++)
	{
		if (m_objectsList[i] != 0)
		{
			m_objectsList[i]->render();
		}
	}
}