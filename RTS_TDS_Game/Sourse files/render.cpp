/////////////////////////
// Include
#include "render.h"
#include "camera.h"

Render::Render()
{
	for (int i = 0; i < CameraType_Count; i++)
	{
		m_cameras[i] = 0;
	}
}

Render::~Render()
{
	delete[] m_cameras;
}

void Render::setup(int width, int height, std::string name)
{
	m_renderWindow = new sf::RenderWindow(
		sf::VideoMode(width, height, 32),
		name,
		sf::Style::Titlebar | sf::Style::Close
	);

	for (int i = 0; i < CameraType_Count; i++)
	{
		m_cameras[i] = new Camera();
	}
}

bool Render::frame()
{
	// End if window is closed
	if (!m_renderWindow->isOpen())
		return false;

	// Check events
	sf::Event event;
	while (m_renderWindow->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_renderWindow->close();
	}

	// Draw image from cameras
	for (int i = 0; i < CameraType_Count; i++)
	{
		m_renderWindow->draw(m_cameras[i]->getSprite());
	}

	m_renderWindow->display();

	return true;
}