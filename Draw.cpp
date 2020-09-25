#pragma once
#include "Engine.h"

using namespace sf;



void Engine::draw()
{

	//Clear the last frame
	m_Window.clear(Color::Cyan);
	

	//Draw the background
	m_Window.draw(m_BackgroundSprite);

	
	//Spawn and draw the cupcakes
	cupcake.update(m_Window);
	cupcake.draw(m_Window);
	

	m_Window.display();


	

}


