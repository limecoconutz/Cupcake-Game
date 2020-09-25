#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Player.h"
#include "Cupcake.h"
#include "FrameTimer.h"


class Engine
{
public:
	//Constructor
	Engine();

	//run all the private functions
	void run();
	

private:
	
	//Private functions. Run will call all private functions 
	void input();
	void draw();
	void updateMousePosition();

	//Prepare the player
	Player player;
	//Prepare the cupcake
	Cupcake cupcake;

	//The usual RenderWindow
	sf::RenderWindow m_Window;

	//What are the screen height and width? (to be used in spawn() and update())
	unsigned int m_heightOfScreen = sf::VideoMode::getDesktopMode().height;
	unsigned int m_widthOfScreen = sf::VideoMode::getDesktopMode().width;

	//Declare a sprite and a texture for the background
	sf::Sprite m_BackgroundSprite;
	sf::Texture m_BackgroundTexture;

	//How many seconds, in gametime, have passed?
	FrameTimer ft;
	const float m_dt = ft.Mark();

	//Is the game currently playing?
	bool m_Playing = true;

	//How much time has passed in-game?
	sf::Time m_GameTimeTotal;

	//Where is the mouse on the screen?
	sf::Vector2i m_mousePosition_Window;
	sf::Vector2f m_mousePosition;
	sf::FloatRect m_mouseRect;


	
};

