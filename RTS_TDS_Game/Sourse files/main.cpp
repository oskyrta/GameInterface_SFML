#include "game.h"
#include "render.h"
#include "dataManager.h"
#include "interface\interface.h"
#include "inputController.h"
#include "eventSystem\eventController.h"

Render* render;
Interface* gameInterface;
DataManager* dataManager;
InputController* inputController;
EventController* eventController;

void setup()
{
	render = Render::instance();
	gameInterface = Interface::instance();
	dataManager = DataManager::instance();
	inputController = InputController::instance();
	eventController = EventController::instance();

	dataManager->loadData();
	inputController->setup();

	render->setup(720, 380, "Game");
	render->setupCamera(CameraType_Main, 720, 380);

	gameInterface->setupInterface();

}

void initialize()
{
	gameInterface->initialize();
}

bool loop()
{
	if( !render->frame() )
		return false;

	render->clear();
	gameInterface->render();
	render->draw();

	eventController->update();

	inputController->update();
	gameInterface->update();

	return true;
}

int main()
{
	setup();
	initialize();
	while (loop());

	return 0;
}