#pragma once
#include <SFML/Graphics.hpp>



class Player 
{
public:
	//Constructor/Destructor
	Player();
	~Player();
	/*void spawn();*/



	//Getting functions
	int getHealth() { return m_health; }
	int getPoints() { return m_points; }
	/*sf::FloatRect getPosition() { return m_Sprite.getGlobalBounds(); }*/

	//Check if player is still alive
	bool isAlive();

	//Reduce the player health
	int decreaseHealth() { m_health -= 1; return m_health; }
	int increasePoints() { m_points += 1; return m_points; }


private:

	//Game logic
	unsigned int m_points;
	int m_health;
	bool m_dead;

	////Player sprite
	//sf::Sprite m_Sprite;
};

