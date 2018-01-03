#include "game.h"
#include "render.h"

Render render;

void setup()
{
	render = Render::instance();

	render.setup(720, 380, "Game");
	render.setupCamera(CameraType_Main, 720, 380);
}

void initialize()
{

}

bool loop()
{
	if( !render.frame() ) return false;

	return true;
}

int main()
{
	setup();
	initialize();
	while (loop());

	return 0;
}