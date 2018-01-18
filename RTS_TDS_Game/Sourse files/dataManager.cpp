#define _CRT_SECURE_NO_WARNINGS

////////////////////////////////////
// Include
#include "dataManager.h"
#include <Windows.h>
#include <filesystem>
#include <string>
#include <strstream>
#include <list>

#include <iostream>

namespace fs = std::experimental::filesystem;

////////////////////////////////////
// Functions
bool compareTex(SpriteContainer& i, SpriteContainer& j) { return i.texturePtr->getSize().y > j.texturePtr->getSize().y; };

////////////////////////////////////
// Class SpriteContainer
bool SpriteContainer::operator==(const std::string& a)
{
	if (a == this->name) return true;
	else return false;
}

////////////////////////////////////
// Class DataManager
DataManager::~DataManager() 
{
	boost::property_tree::info_parser::write_info(m_rep + "interface.info", m_interface);
	boost::property_tree::info_parser::write_info(m_rep + "binds.info", m_binds);
}

sf::Font* DataManager::getFont() { return m_font; }

SpriteContainer* DataManager::getSpriteContainer(std::string name)
{
	for (auto & s : m_sprites)
		if (s == name) return &s;

	return 0;
}

void DataManager::loadSettings()
{
	std::ifstream in(m_rep + "binds.info");
	boost::property_tree::info_parser::read_info(in, m_binds);
	in.close();

	in.open(m_rep + "interface.info");
	boost::property_tree::info_parser::read_info(in, m_interface);
	in.close();
}

void DataManager::loadSprites()
{
	int spritesCount = 0;

	std::strstream paths;
	std::string pathToSprites = m_rep + "Sprites\\", path;

	for (auto & p : fs::directory_iterator(pathToSprites))
	{
		// Get path to sprite
		paths << p;
		paths >> path;
		paths.clear();

		SpriteContainer container; sf::Texture* tex = new sf::Texture();
		// Write temp texture to container
		container.texturePtr = new sf::Texture();
		container.texturePtr->loadFromFile(path);
		// Write sprite name from path
		container.name = path.substr(pathToSprites.length(), path.length() - pathToSprites.length() - 4);

		//std::cout << container.name << std::endl;

		spritesCount++;
		m_sprites.push_back(container);
	}
	m_sprites.sort(compareTex);

	int currentLevel = 0, nextLevel = 0, levelFill, maxSize;
	levelFill = maxSize = 256;

	for (auto & t : m_sprites)
	{
		if (levelFill + t.texturePtr->getSize().x > maxSize)
		{
			currentLevel = nextLevel;
			nextLevel += t.texturePtr->getSize().y;
			levelFill = 0;
		}

		sf::IntRect rect;
		rect.left = levelFill;
		rect.top = currentLevel;
		rect.width = t.texturePtr->getSize().x;
		rect.height = t.texturePtr->getSize().y;
		t.rect = rect;

		levelFill += rect.width;
	}
	sf::Image atlas;
	atlas.create(maxSize, nextLevel);

	for (auto & t : m_sprites)
	{
		atlas.copy(t.texturePtr->copyToImage(), t.rect.left, t.rect.top);
		t.texturePtr = &m_atlas;
	}
	m_atlas.loadFromImage(atlas);
	//atlas.saveToFile("atlas00.png");
}

void DataManager::loadData()
{
	// Get path to settings folder in AppData\Roaming
	//m_rep = getenv("appdata");
	//m_rep += "\\GameName\\Settings\\";
	m_rep = "Resources\\";

	m_font = new sf::Font();
	m_font->loadFromFile(m_rep + "stan0753.ttf");

	loadSettings();
	loadSprites();
}