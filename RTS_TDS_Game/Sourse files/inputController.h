#pragma once
//////////////////////////////
// Include
#include <boost\property_tree\ptree.hpp>
#include <SFML\Graphics.hpp>
#include "tools\vec2.h"

//////////////////////////////
// Forward declaration
class DataManager;
class Render;
struct Bind;

enum KeyState
{
	KeyState_None = 0,
	KeyState_Down = 1 << 0,
	KeyState_Pressed = 1 << 1,
	KeyState_Up = 1 << 2
};

enum Binds
{
	Bind_None,
	Bind_LeftButton,
	Bind_RightButton,
	Bind_Enter,
	Bind_Esc,
	Bind_Fire,

	Bind_Count
};


//////////////////////////////
// Class InputController
class InputController
{
public:
	InputController() {};

	static InputController* instance()
	{
		static InputController *instance_ = new InputController();
		return instance_;
	};

	short getBindState(Binds bind);
	Vec2 getMousePosition();
	Vec2 getMousePositionC();
	bool mouseOnWindow();

	void setup();
	void update();

private:
	Render* m_render;
	DataManager* m_dataManager;
	boost::property_tree::ptree* m_tree;

	Vec2 m_mousePosition;

	Bind* m_binds[Bind_Count];
};