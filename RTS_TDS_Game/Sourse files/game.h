#pragma once

///////////////////////////
// Class Game
class Game
{
public:
	Game() {};
	~Game();

	// Single initialization
	static Game* instance()
	{
		static Game *instance_ = new Game();
		return instance_;
	};

	void setup();
	void update(float dt);
	void render();

private:
};