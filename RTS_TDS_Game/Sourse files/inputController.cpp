///////////////////////////////
// Include
#include "inputController.h"
#include "dataManager.h"
#include "render.h"
#include "tools\utils.h"
#include <boost\foreach.hpp>
#include <boost\property_tree\ptree.hpp>

////////////////////////////////////////
// Enum
enum Controls
{
	LEFT_BUTTON = 0x01,
	RIGHT_BUTTON = 0x02,
	ENTER_KEY = 0x0D,
	ESC_KEY = 0x1B,
};

////////////////////////////////////////
// Struct Bind
struct Bind
{
	void setState(bool isPressed);

	short state = 0;
	short firstKey = 0;
	short secondKey = 0;
};

void Bind::setState(bool isPressed)
{
	if (isPressed)
	{
		if (!(state & KeyState_Pressed))
		{
			state = 0;
			state |= KeyState_Down;
			state |= KeyState_Pressed;
		}
		else
		{
			state = 0;
			state |= KeyState_Pressed;
		}
	}
	else
	{
		if (state & KeyState_Pressed)
		{
			state = 0;
			state |= KeyState_Up;
		}
		else
		{
			state = 0;
		}
	}
}

////////////////////////////////////////
// Finctions
Binds GetBindByName(std::string name)
{
	if (name == "Fire") return Bind_Fire;

	return Bind_None;
}

///////////////////////////////
// Class InputController

static Vec2 size;

void InputController::setup()
{
	m_dataManager = DataManager::instance();
	m_render = Render::instance();
	m_tree = m_dataManager->getBinds();
	
	for (int i = 0; i < Bind_Count; i++)
		m_binds[i] = new Bind();

	m_binds[1]->firstKey = LEFT_BUTTON;
	m_binds[2]->firstKey = RIGHT_BUTTON;
	m_binds[3]->firstKey = ENTER_KEY;
	m_binds[4]->firstKey = ESC_KEY;

	BOOST_FOREACH(auto& var, *m_tree)
	{
		m_binds[GetBindByName(var.first)]->firstKey = var.second.get<short>("");
	}
}

void InputController::update()
{
	size = (sf::Vector2f)m_render->getSize();
	m_mousePosition = m_render->getRenderWindow()->mapPixelToCoords( sf::Mouse::getPosition(*m_render->getRenderWindow()) );

	for (int i = 0; i < Bind_Count; i++)
		m_binds[i]->setState(IsKeyDown(m_binds[i]->firstKey) || IsKeyDown(m_binds[i]->secondKey));
}

short InputController::getBindState(Binds bind)
{
	 return m_binds[bind]->state; 
}

Vec2 InputController::getMousePosition()
{
	return m_mousePosition;
}

Vec2 InputController::getMousePositionC()
{
	return m_mousePosition - size/2;
}

bool InputController::mouseOnWindow()
{
	if (m_mousePosition.x < 0 || m_mousePosition.y < 0 || m_mousePosition.x > size.x || m_mousePosition.y > size.y) return false;
	
	return true;
}