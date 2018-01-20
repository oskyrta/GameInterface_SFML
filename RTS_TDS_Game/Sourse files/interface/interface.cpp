/////////////////////////////////////////////////
// Include
#include "interface\interface.h"
#include "interface\interfaceWindow.h"
#include "interface\uiButton.h"
#include "interface\uiText.h"
#include "interface\uiSprite.h"

#include "game.h"
#include "render.h"
#include "dataManager.h"
#include "eventSystem\eventController.h"
#include "inputController.h"
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
	m_render = Render::instance();
	m_eventController = EventController::instance();
	m_dataManager = DataManager::instance();

	startListeningEvents();

	for (int i = 0; i < MenuTypeCount; i++)
	{
		m_menuList[i] = 0;
	}
}

void Interface::startListeningEvents()
{

}

double t_x, t_y;

void Interface::initialize()
{
	for (int i = 0; i < MenuTypeCount; i++)
	{
		std::string menuName = getMenuNameByType((MenuType)i);

		m_menuList[i] = new InterfaceWindow();
		m_menuList[i]->setCamera(m_render->getCamera(menuName));
		m_menuList[i]->initialize(menuName);
	}

	UIText* obj = (UIText*)m_menuList[MenuType_MainMenu]->getObject("TextX");
	obj->setChangedValue(&t_x);

	obj = (UIText*)m_menuList[MenuType_MainMenu]->getObject("TextY");
	obj->setChangedValue(&t_y);
}

void Interface::changeWindow(MenuType windowType)
{
	m_menuList[activeWindowIndex]->setActive(false);
	activeWindowIndex = windowType;
	m_menuList[activeWindowIndex]->setActive(true);
}

void Interface::update()
{
	t_x = InputController::instance()->getMousePosition().x;
	t_y = InputController::instance()->getMousePosition().y;
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