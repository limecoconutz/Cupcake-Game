#pragma once
#include <SFML/Graphics.hpp>


class HUD
{
public:
	HUD();

	sf::Text getMessage();
	sf::Text getTime();

	void setTime(std::string text);

private:
	sf::Font m_Font;
	sf::Text m_StartText;
	sf::Text m_TimeText;
	sf::Text m_LevelText;

};

