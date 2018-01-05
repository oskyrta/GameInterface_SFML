#pragma once
////////////////////////////////////////////////
// Include
#include <string>
#include <list>
#include <SFML\Graphics.hpp>
#include "tools/vec2.h"

////////////////////////////////////////////////
// Forvard declaration
class Camera;
class UIObject;
class EventController;
class DataManager;

typename PropertyTree;

////////////////////////////////////////////////
// Class InterfaceWindow
class InterfaceWindow
{
public:
	InterfaceWindow();
	~InterfaceWindow();

	void initialize(std::string name);

	void createButtons();
	void createTexts();
	void createSprites();

	void update();
	void render();

	void setActive(bool active) { m_isActive = active; };
	bool getActive() { return m_isActive; };

	void setEventController(EventController* ec) { m_eventController = ec; };
	void setCamera(Camera* camera) { m_camera = camera; };

private:
	std::list<UIObject*> m_objectsList;
	bool m_isActive;

	EventController* m_eventController;

	PropertyTree* m_objects;

	Camera* m_camera;
	DataManager* m_dataManager;
};