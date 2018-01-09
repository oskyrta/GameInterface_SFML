///////////////////////////////
// Include
#include "inputController.h"
#include "dataManager.h"
#include "tools\utils.h"
#include <boost\foreach.hpp>
#include <boost\property_tree\ptree.hpp>

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
}

///////////////////////////////
// Class InputController

void InputController::setup()
{
	m_dataManager = DataManager::instance();
	m_tree = m_dataManager->getBinds();

	int i = 0;

	for (int i = 0; i < 4; i++)
		m_controls[i] = new Bind();
	
	for (int i = 0; i < Bind_Count; i++)
		m_binds[i] = new Bind();

	m_controls[0]->firstKey = LEFT_BUTTON;
	m_controls[1]->firstKey = RIGHT_BUTTON;
	m_controls[2]->firstKey = ENTER_KEY;
	m_controls[3]->firstKey = ESC_KEY;

	BOOST_FOREACH(auto& var, *m_tree)
	{
		m_binds[GetBindByName(var.first)]->firstKey = var.second.get<short>("");
	}
}

void InputController::update()
{
	for (int i = 0; i < 4; i++)
		m_controls[i]->setState(IsKeyDown(m_controls[i]->firstKey));

	for (int i = 0; i < Bind_Count; i++)
		m_binds[i]->setState(IsKeyDown(m_binds[i]->firstKey) || IsKeyDown(m_binds[i]->secondKey));
}