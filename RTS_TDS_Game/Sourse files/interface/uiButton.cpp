/////////////////////////////////////////////////
// Include
#include "uiButton.h"
#include "eventSystem\eventController.h"
#include "tools\utils.h"
#include "camera.h"

/////////////////////////////////////////////////
// Variable 
bool leftClick = false;

/////////////////////////////////////////////////
// Class UIButton
UIButton::UIButton()
{
	m_eventController = EventController::instance();
}

UIButton::~UIButton()
{

}


void UIButton::initialize(PropertyTree* tree)
{
	m_tree = tree;

	m_pos.x = (int)(m_tree->get<float>("x") * m_camera->getHalfSize().x);
	m_pos.y = (int)(m_tree->get<float>("y") * m_camera->getHalfSize().y);

	m_size.x = m_tree->get<int>("width");
	m_size.y = m_tree->get<int>("height");

	m_event = m_tree->get<std::string>("Event");

	m_string = m_tree->get<std::string>("String");
	if (m_string != "")
	{
		m_characterSize = m_tree->get<int>("CharacterSize");
		m_color.r = m_tree->get<int>("Color.r");
		m_color.g = m_tree->get<int>("Color.g");
		m_color.b = m_tree->get<int>("Color.b");
		initializeText();
	}

	m_spriteName = m_tree->get<std::string>("SpriteName");
	if (m_spriteName != "")
	{
		//
		// Place for sprite initialize
		//
	}
}

void UIButton::update()
{

}

void UIButton::render()
{
	//UISprite::render();
	UIText::render();
}