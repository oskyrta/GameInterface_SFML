////////////////////////////////////
// Include
#include "dataManager.h"
#include <Windows.h>

////////////////////////////////////
// Class DataManager
DataManager::~DataManager() 
{
	boost::property_tree::info_parser::write_info(m_rep + "inteface.info", m_interface);
	boost::property_tree::info_parser::write_info(m_rep + "binds.info", m_binds);
}

void DataManager::loadData()
{
	// Get path to settings folder in AppData\Roaming
	//m_rep = getenv("appdata");
	//m_rep += "\\GameName\\Settings\\";
	m_rep = "Resources\\";

	m_font.loadFromFile(m_rep + "stan0753.ttf");

	std::ifstream in(m_rep + "binds.info");
	boost::property_tree::info_parser::read_info(in, m_binds);
	in.close();

	in.open(m_rep + "inteface.info");
	boost::property_tree::info_parser::read_info(in, m_interface);
	in.close();
}