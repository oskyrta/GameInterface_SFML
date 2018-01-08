///////////////////////////////
// Include
#include "inputController.h"
#include "dataManager.h"
#include <boost\foreach.hpp>

///////////////////////////////
// Class InputController

void InputController::setup()
{
	m_dataManager = DataManager::instance();
	m_tree = m_dataManager->getBinds();
	
	int i = 0;
}