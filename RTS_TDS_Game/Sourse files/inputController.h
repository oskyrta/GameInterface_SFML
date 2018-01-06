#pragma once
//////////////////////////////
// Include

//////////////////////////////
// Forward declaration
class DataManager;

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
};