/////////////////////////////////////////////////
// Include
#include "interface\interface.h"
#include "interface\interfaceWindow.h"
#include "game.h"
#include "eventSystem\eventController.h"
#include "interface\uiButton.h"
#include "interface\uiText.h"
#include "interface\uiSprite.h"
#include "tools/utils.h"


/////////////////////////////////////////////////
// Variables
static MenuType activeWindowIndex = MenuType_MainMenu;

/////////////////////////////////////////////////
// Functions
std::string getMenuNameByType(MenuType type)
{
	switch (type)
	{
		case MenuType_MainMenu: return "Main";
	}

	return "";
}

/////////////////////////////////////////////////
// Class Interface

Interface::~Interface()
{
	for (int i = 0; i < MenuTypeCount; i++)
	{
		if (m_menuList[i] != 0)
		{
			delete m_menuList[i];
			m_menuList[i] = 0;
		}
	}
}

void Interface::setupInterface()
{
	m_game = Game::instance();
	m_eventController = EventController::instance();

	startListeningEvents();

	for (int i = 0; i < MenuTypeCount; i++)
	{
		m_menuList[i] = 0;
	}
}

void Interface::startListeningEvents()
{
}

void Interface::initialize()
{

}

void Interface::changeWindow(MenuType windowType)
{
	m_menuList[activeWindowIndex]->setActive(false);
	activeWindowIndex = windowType;
	m_menuList[activeWindowIndex]->setActive(true);
}

void Interface::update()
{
	changeWindow(activeWindowIndex);

	m_menuList[activeWindowIndex]->update();
}

void Interface::render()
{
	m_menuList[activeWindowIndex]->render();
}

InterfaceWindow* Interface::createWindow(MenuType type)
{
	m_menuList[type] = new InterfaceWindow();
	m_menuList[type]->setActive(true);

	return m_menuList[type];
}