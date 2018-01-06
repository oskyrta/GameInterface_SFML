#pragma once
////////////////////////////////////////////////
// Include
#include "uiText.h"
#include "uiSprite.h"

////////////////////////////////////////////////
// Forvard declaration
class EventController;

////////////////////////////////////////////////
// Class GUIButton
class UIButton : public UIText, public UISprite
{
public:
	UIButton();

	virtual void render();
	virtual void update();

	void initialize(PropertyTree& tree);

	void setEvent(std::string gameEvent) { m_event = gameEvent; };
	void setEventController(EventController* controller) { m_eventController = controller; };
	void setSprite(std::string spriteName) { UISprite::initialize(spriteName); UISprite::setHalfSizeAutomatically(); };

private:
	std::string m_event;
	EventController* m_eventController;
};