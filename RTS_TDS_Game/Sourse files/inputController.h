#pragma once
//////////////////////////////
// Include
#include <boost\property_tree\ptree.hpp>

//////////////////////////////
// Forward declaration
class DataManager;
class Vec2;
struct Bind;

enum Controls
{
	LEFT_BUTTON = 0x01,
	RIGHT_BUTTON = 0x02,
	ENTER_KEY = 0x0D,
	ESC_KEY = 0x1B,
};

enum KeyState
{
	KeyState_None = 0,
	KeyState_Down = 1 << 0,
	KeyState_Pressed = 1 << 1,
	KeyState_Up = 1 << 2
};

enum Binds
{
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

	short GetBindState(Binds bind) { return m_binds[bind]->state; }
	Vec2 GetMousePosition();
	bool MouseOnWindow();

	void setup();
	void update();

private:
	DataManager* m_dataManager;
	boost::property_tree::ptree* m_tree;

	Bind* m_binds[Bind_Count];
	Bind* m_controls[4];
};