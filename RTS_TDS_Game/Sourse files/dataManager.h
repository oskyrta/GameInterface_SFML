#pragma once
///////////////////////////////////
//Include
#include <boost\property_tree\ptree.hpp>
#include <boost\property_tree\info_parser.hpp>
#include <string>
#include <SFML\Graphics.hpp>

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

	boost::property_tree::ptree* getBinds() { return &m_binds; }
	boost::property_tree::ptree* getInterfaceSettings() { return &m_interface; }

	sf::Font* getFont();

private:
	std::string m_rep; 
	boost::property_tree::ptree m_binds;
	boost::property_tree::ptree m_interface;

	sf::Font* m_font;
};