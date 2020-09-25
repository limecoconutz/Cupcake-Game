#include "HUD.h"

using namespace sf;

HUD::HUD()
{
	Vector2u resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	// Load the font
	m_Font.loadFromFile("Fonts/BeckyTahlia-MP6r.ttf");

	//// Paused
	//m_StartText.setFont(m_Font);
	//m_StartText.setCharacterSize(100);
	//m_StartText.setFillColor(Color::White);
	//m_StartText.setString("Press Enter when ready!");

	// Position the text
	FloatRect textRect = m_StartText.getLocalBounds();

	m_StartText.setOrigin(textRect.left +
		textRect.width / 2.0f,
		textRect.top +
		textRect.height / 2.0f);

	m_StartText.setPosition(resolution.x / 2.0f, resolution.y / 2.0f);

	// Time
	m_TimeText.setFont(m_Font);
	m_TimeText.setCharacterSize(75);
	m_TimeText.setFillColor(Color::White);
	m_TimeText.setPosition(resolution.x - 150, 0);
	m_TimeText.setString("------");

}

sf::Text HUD::getMessage()
{
    return m_StartText;
}

sf::Text HUD::getTime()
{
    return m_TimeText;

}

void HUD::setTime(std::string text)
{
    m_TimeText.setString(text);
}
