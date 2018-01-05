#pragma once
////////////////////////////////////////////////
// Include
#include "eventSystem\eventListener.h"

////////////////////////////////////////////////
// Forvard declaration
class InterfaceWindow;
class EventController;
class DataManager;
class Render;
class Game;

////////////////////////////////////////////////
// Enum
enum MenuType
{
	MenuType_MainMenu,

	MenuTypeCount
};

////////////////////////////////////////////////
// Class Interface
class Interface: public EventListener
{
public:
	Interface() {};
	~Interface();

	static Interface& instance()
	{
		static Interface *instance_ = new Interface();
		return *instance_;
	};

	void setupInterface();
	void initialize();
	void update();
	void render();

private:
	InterfaceWindow* createWindow(MenuType type);
	void changeWindow(MenuType windowType);

	void startListeningEvents();

private:
	InterfaceWindow* m_menuList[MenuTypeCount];

	EventController* m_eventController;
	Game* m_game;
	Render* m_render;
	DataManager* m_dataManager;
};