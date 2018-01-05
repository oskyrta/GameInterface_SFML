#pragma once
/////////////////////////////////////////////////
// Include
#include "tools/vec2.h"

/////////////////////////////////////////////////
// Forvard declaration
class Camera;

/////////////////////////////////////////////////
// Class GUIObject
class UIObject
{
public:
	UIObject();
	UIObject(Camera* camera, std::string tag, Vec2 halfSize);
	virtual ~UIObject() ;

	virtual void render() {};
	virtual void update();

	virtual void initialize() {};

	void setPosition(Vec2 pos) { m_pos = pos; };
	void setPosition(float x, float y) { m_pos = Vec2(x, y); }
	void setSize(Vec2 size) { m_size = size; };
	void setSize(float width, float height) { m_size = Vec2(width, height); }
	void setCamera(Camera* camera) { m_camera = camera; };
	void setName(std::string name) { m_name = name; };

	Vec2 getSize() { return m_size; };
	bool getMouseOnObject() { return m_mouseOnObject; };

protected:
	bool m_mouseOnObject;

	Vec2 m_pos;
	Vec2 m_size;

	std::string m_name;

	Camera* m_camera;
};