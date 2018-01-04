#pragma once
////////////////////////
// Include
#include "SFML\Graphics.hpp"

////////////////////////
// Enum
enum CameraType
{
	CameraType_Main,

	CameraType_Count
};

////////////////////////
// Forward declaration
class Camera;

////////////////////////
// Class Render
class Render
{
public:
	Render() {};
	~Render();

	// Single initialization
	static Render* instance()
	{
		static Render *instance_ = new Render();
		return instance_;
	};

	void setup(int width, int height, std::string name);
	void setupCamera(CameraType type, int width, int height);
	bool frame();
private:
	Camera* m_cameras[CameraType_Count];

	sf::RenderWindow *m_renderWindow;
};