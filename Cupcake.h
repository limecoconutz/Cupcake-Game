#pragma once
#include <iostream>
#include <vector>
#include<algorithm>


#include "TextureHolder.h"
#include "FrameTimer.h"




class Cupcake 
{
public:
	//Constructor - Destructor
	Cupcake();
	~Cupcake();

	
	/*void interact(sf::Window& w);*/
	void update(sf::RenderWindow& w);
	/*void eraseCupcake();*/

	//Render the cupcakes
	void draw(sf::RenderWindow &w);
	
	//Inlined functions
	std::vector<sf::Sprite> getSprites() { return  m_spriteVector; }
	

	std::vector<sf::Sprite> m_spriteVector;

private:
	/*
	Private functions (to be used in update() )
	*/
	//Create and update the cupcakes
	void spawn();
	void move();
	void removeCupcake();

	/*
	Private variables
	*/
	//What are the screen height and width? (to be used in spawn() and update())
	unsigned int m_screenHeight = sf::VideoMode::getDesktopMode().height;
	unsigned int m_screenWidth = sf::VideoMode::getDesktopMode().width;

	//How far from each other are cupcakes spawning?
	float m_cupcakeSpawnTimerMax = 80.f;
	float m_cupcakeSpawnTimer = m_cupcakeSpawnTimerMax;
	
	//What is the maximum number of cupcakes generated?
	double m_maxCupcakes;
	
	//How fast is the cupcake moving
	float m_cupcakeSpeed;

	//Cupcake sprite handling
	sf::Sprite m_cupcakeSprite;
	//Has the cupcake been deleted?
	bool m_deleted;

	//Where is the cupcake?
	sf::FloatRect m_bounds;

	
};

