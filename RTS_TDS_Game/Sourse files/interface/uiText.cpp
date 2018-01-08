#define _SCL_SECURE_NO_WARNINGS

////////////////////////////////////////////////
// Include
#include "uiText.h"
#include "camera.h"
#include "dataManager.h"

////////////////////////////////////////////////
// Class UIText

UIText::UIText()
{
	m_font = 0;
	m_intChangedValue = 0;
	m_doubleChangedValue = 0;
	m_characterSize = 8;
	m_align = TextAlign_Left;

	m_changedValuePosition = 0;

	m_text = sf::Text();
}

void UIText::initialize(PropertyTree& tree)
{
	m_tree = tree;
	m_string = m_tree.get<std::string>("String");
	m_pos.x = m_tree.get<int>("x");
	m_pos.y = m_tree.get<int>("y");
	m_characterSize = m_tree.get<int>("CharacterSize");
	m_color.r = m_tree.get<int>("Color.r");
	m_color.g = m_tree.get<int>("Color.g");
	m_color.b = m_tree.get<int>("Color.b");

	initializeText();
}

void UIText::initializeText()
{
	// Initialize text variable
	m_text.setFont(*m_dataManager->getFont());
	m_text.setPosition(m_pos.x + m_size.x, m_pos.y - m_characterSize/2);
	m_text.setCharacterSize(m_characterSize);
	m_text.setString(m_string);
	m_text.setFillColor(m_color);

	m_textSize.x = m_text.getLocalBounds().width;
	m_textSize.y = m_text.getLocalBounds().height;

	int i = 0;
	while(i < m_string.size())
	{
		if (m_string[i] == '^')
		{
			m_changedValuePosition = i;
			break;
		}
		i++;
	}

	m_string.copy(s_start, m_changedValuePosition, 0);
	if(m_changedValuePosition > 0)
		m_string.copy(s_end, m_string.size() - (m_changedValuePosition + 1), m_changedValuePosition+1);
}

void UIText::render()
{
	if (m_intChangedValue) 
		m_text.setString(s_start + std::to_string(*m_intChangedValue) + s_end);
	if (m_doubleChangedValue)
		m_text.setString(s_start + std::to_string(*m_doubleChangedValue) + s_end);

	sf::Vector2f position = getTextPosition();
	m_text.setPosition(position);

	m_camera->getRenderWindow()->draw(m_text);
}


sf::Vector2f UIText::getTextPosition()
{ 
	return sf::Vector2f(m_camera->getPosition().x + m_textOffset.x + m_pos.x - m_size.x, m_camera->getPosition().y + m_textOffset.y + m_pos.y - m_characterSize / 2); 
};
