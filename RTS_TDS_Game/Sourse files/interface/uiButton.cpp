/////////////////////////////////////////////////
// Include
#include "uiButton.h"
#include "eventSystem\eventController.h"
#include "tools\utils.h"
#include <Windows.h>

/////////////////////////////////////////////////
// Variable 
bool leftClick = false;

/////////////////////////////////////////////////
// Class UIButton
UIButton::UIButton()
{
	m_eventController = EventController::instance();
}

void UIButton::update()
{
	UIObject::update();

	leftClick = false;
	if (m_eventController->getEventState(GameEvent_LeftButtonDown)) leftClick = true;

	if (m_mouseOnObject && !IsKeyDown(0x70)) m_textOffset.x += 2;
	else m_textOffset.x -= 2;

	if (m_textOffset.x < 0) m_textOffset.x = 0;
	if (m_textOffset.x > 8) m_textOffset.x = 8;

	if (leftClick && m_mouseOnObject && !IsKeyDown(0x70))
	{
		m_eventController->startEvent(m_event);
	}
}

void UIButton::render()
{
	UISprite::render();
	UIText::render();
}