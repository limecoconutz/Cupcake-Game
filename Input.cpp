#pragma once
#include "Engine.h"
using namespace sf;


void Engine::input()
{
	Event event;
	updateMousePosition();

	//Handle the player quitting
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		m_Window.close();

	}

	////Handle the player starting the game
	//if (Keyboard::isKeyPressed(Keyboard::Return))
	//{m_Playing = true;} else {m_Playing = false;}

	//Handle Mouse clicking
	if (Mouse::isButtonPressed(Mouse::Left) && m_Playing == true)
	{
		
		std::vector<sf::Sprite> &cupcakes = cupcake.m_spriteVector;
		
		for (int c = 0; c < cupcakes.size(); c++)
		{
			//if the cupcake has left the screen
			if (cupcakes[c].getPosition().y >= m_Window.getSize().y)
			{
				//delete the cupcake
				cupcakes.erase(cupcakes.begin() + c);

				//decrease player health
				player.decreaseHealth();
				//print-out health for testing purposes
				std::cout << "Health: " << player.getHealth() << "\n";
			}

			//if the cupcake is clicked on
			if (cupcakes[c].getGlobalBounds().contains(m_mousePosition))
			{
				//increase player points
				player.increasePoints();
				//print-out points for testing purposes
				std::cout << "Points: " << player.getPoints() << "\n";

				//delete cupcake sprite
				cupcakes.erase(cupcakes.begin() + c);
			}

			
		}
			
	}
}