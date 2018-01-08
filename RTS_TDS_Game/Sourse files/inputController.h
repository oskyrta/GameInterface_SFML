#pragma once
//////////////////////////////
// Include
#include <boost\property_tree\ptree.hpp>

typedef boost::property_tree::ptree PropertyTree;

//////////////////////////////
// Forward declaration
class DataManager;

enum class Binds
{
	Fire,

	Count
};

struct Bind
{
	enum KeyState
	{
		None,
		Down,
		Stay,
		Up
	};
private:
	short firstKey;
	short secondKey;
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

	void setup();

private:
	DataManager* m_dataManager;
	PropertyTree* m_tree;

	Bind m_binds[(int)Binds::Count];
};