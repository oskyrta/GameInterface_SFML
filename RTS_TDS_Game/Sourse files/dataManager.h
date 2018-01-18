#pragma once
///////////////////////////////////
//Include
#include <boost\property_tree\ptree.hpp>
#include <boost\property_tree\info_parser.hpp>
#include <string>
#include <list>
#include <SFML\Graphics.hpp>

///////////////////////////////////
// Sturct
struct SpriteContainer
{
	std::string name;
	sf::IntRect rect;
	sf::Texture *texturePtr;

	bool operator==(const std::string& a);
};

///////////////////////////////////
// Class DataManager
class DataManager
{
public:
	DataManager() {};
	~DataManager();

	static DataManager* instance()
	{
		static DataManager *instance_ = new DataManager();
		return instance_;
	};

	void loadData();
	SpriteContainer* getSpriteContainer(std::string name);

	boost::property_tree::ptree* getBinds() { return &m_binds; }
	boost::property_tree::ptree* getInterfaceSettings() { return &m_interface; }

	sf::Font* getFont();

private:
	void loadSettings();
	void loadSprites();

private:
	std::string m_rep; 
	boost::property_tree::ptree m_binds;
	boost::property_tree::ptree m_interface;

	sf::Font* m_font;
	sf::Texture m_atlas;

	std::list<SpriteContainer> m_sprites;
};