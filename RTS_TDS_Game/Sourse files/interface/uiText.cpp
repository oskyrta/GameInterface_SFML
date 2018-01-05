#define _SCL_SECURE_NO_WARNINGS

////////////////////////////////////////////////
// Include
#include "uiText.h"
#include "camera.h"

////////////////////////////////////////////////
// Class UIText

UIText::UIText()
{
	m_font = 0;
	m_intChangedValue = 0;
	m_doubleChangedValue = 0;
	m_characterSize = 8;

	m_changedValuePosition = 0;

	m_text = sf::Text();
}

void UIText::initialize(std::string string, sf::Font* font, int characterSize, sf::Color color)
{
	// Initialize text variable
	m_text.setFont(*font);
	m_text.setPosition(m_pos.x + m_size.x, m_pos.y - characterSize/2);
	m_text.setCharacterSize(characterSize);
	m_text.setString(string);
	m_text.setFillColor(color);

	// Initialize
	m_string = string;
	m_characterSize = characterSize;

	int i = 0;
	while(i < string.size())
	{
		if (string[i] == '^')
		{
			m_changedValuePosition = i;
			break;
		}
		i++;
	}

	string.copy(s_start, m_changedValuePosition, 0);
	if(m_changedValuePosition > 0)
		string.copy(s_end, string.size() - (m_changedValuePosition + 1), m_changedValuePosition+1);
}

void UIText::render()
{
	if (m_intChangedValue) 
		m_text.setString(s_start + std::to_string(*m_intChangedValue) + s_end);
	if (m_doubleChangedValue)
	{
		m_text.setString(s_start + std::to_string(*m_doubleChangedValue) + s_end);
	}

	sf::Vector2f position = getTextPosition();
	m_text.setPosition(position);

	m_camera->getRenderWindow()->draw(m_text);
}


sf::Vector2f UIText::getTextPosition()
{ 
	return sf::Vector2f(m_camera->getPosition().x + m_textOffset.x + m_pos.x - m_size.x, m_camera->getPosition().y + m_textOffset.y + m_pos.y - m_characterSize / 2); 
};
