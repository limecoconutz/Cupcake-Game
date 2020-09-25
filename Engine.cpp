#include "Engine.h"
using namespace sf;

//Public functions only here (private functions in Input.cpp, Update.cpp and Draw.cpp respectively)


Engine::Engine()
{
	

	//Get the screen resolution and create an SFML window and fullscreen view
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	m_Window.create(VideoMode(resolution.x, resolution.y), "Catch all the Cupcakes game!!!", Style::Fullscreen);
	//m_Window.setFramerateLimit(60);
	
	//Associate the sprite with the texture and set the position to render
	m_BackgroundSprite = Sprite(TextureHolder::GetTexture("Images/background.png"));
	m_BackgroundSprite.setPosition(0, 0);

	
	
}

void Engine::run()
{
	//Timing
	Clock clock;


	while (m_Window.isOpen())
	{
		Time dt = clock.restart();
		//Update the total game time
		m_GameTimeTotal += dt;
		
				//Call each part of the game loop in turn
				input();
				
				draw();
	}

		
	
}




