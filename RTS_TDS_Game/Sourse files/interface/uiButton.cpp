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

void UIButton::initialize(PropertyTree& tree)
{
	m_tree = tree;

	m_pos.x = m_tree.get<int>("x");
	m_pos.y = m_tree.get<int>("y");

	m_size.x = m_tree.get<int>("width");
	m_size.y = m_tree.get<int>("height");

	m_event = m_tree.get<int>("Event");

	m_string = m_tree.get<std::string>("String");
	if (m_string != "")
	{
		m_characterSize = m_tree.get<int>("CharacterSize");
		m_color.r = m_tree.get<int>("Color.r");
		m_color.g = m_tree.get<int>("Color.g");
		m_color.b = m_tree.get<int>("Color.b");
		initializeText();
	}

	m_spriteName = m_tree.get<std::string>("SpriteName");
	if (m_spriteName != "")
	{
		//
		// Place for sprite initialize
		//
	}
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