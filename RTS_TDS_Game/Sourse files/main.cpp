#include "game.h"
#include "render.h"
#include "dataManager.h"

Render* render;
DataManager* dataManager;

void setup()
{
	render = Render::instance();
	dataManager = DataManager::instance();

	render->setup(720, 380, "Game");
	render->setupCamera(CameraType_Main, 720, 380);

	dataManager->loadData();
}

void initialize()
{

}

bool loop()
{
	if( !render->frame() ) return false;

	return true;
}

int main()
{
	setup();
	initialize();
	while (loop());

	return 0;
}