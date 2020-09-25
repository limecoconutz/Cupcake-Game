#include "Cupcake.h"
#include "Player.h"

using namespace sf;
//Constructor - Destructor
Cupcake::Cupcake() 
{
	srand((int)time(0));

	//Randomize cupcake speed
	m_cupcakeSpeed = (rand() % 2) + 8;
	m_maxCupcakes = 5;

	//Initialize bool
	m_deleted = false;
	
}

Cupcake::~Cupcake()
{

}


void Cupcake::update(sf::RenderWindow& w)
{
		
		//Update and reset the timer for spawning cupcakes and moving them
		m_cupcakeSpawnTimer += .3f;

		//Update the cupcakes as per last frame
		removeCupcake();
		

		//spawn and move cupcakes
		if (m_cupcakeSpawnTimer > m_cupcakeSpawnTimerMax)
		{
			spawn();
			move();
			m_cupcakeSpawnTimer = 1.f;

		}
		else
		{//Give a cooldown between timer resets
			m_cupcakeSpawnTimer += 0.1f;
		}
		
		
		
}



void Cupcake::spawn()
{//How many seconds in game time have passed?
	FrameTimer ft;
	const double dt = ft.Mark();
		//Set cupcake sprites origin point to be at the center 
		m_cupcakeSprite.setOrigin(sf::Vector2f(25.f, 25.f));

		//Randomize cupcake type
		int type = rand() % 3;
		float x = (rand() % m_screenWidth);

		if (m_spriteVector.size() < m_maxCupcakes)
		{
			switch (type)
			{
			case 0:
				m_cupcakeSprite = Sprite(TextureHolder::GetTexture("Images/Cupcake1.png"));
				m_cupcakeSprite.setScale(0.2f, 0.2f);
				m_cupcakeSprite.setPosition(x, 0.f);
				m_spriteVector.push_back(m_cupcakeSprite);
				break;

			case 1:
				m_cupcakeSprite = Sprite(TextureHolder::GetTexture("Images/Cupcake2.png"));
				m_cupcakeSprite.setScale(0.2f, 0.2f);
				m_cupcakeSprite.setPosition(x, 0.f);
				m_spriteVector.push_back(m_cupcakeSprite);
				break;

			case 2:
				m_cupcakeSprite = Sprite(TextureHolder::GetTexture("Images/Cupcake3.png"));
				m_cupcakeSprite.setScale(0.1f, 0.1f);
				m_cupcakeSprite.setPosition(x, 0.f);
				m_spriteVector.push_back(m_cupcakeSprite);
				break;
			}
		
		}
		else
		{
			m_maxCupcakes += 0.1;
		}
		
	
}


void Cupcake::move()
{
	
	for (int i =0; i<m_spriteVector.size(); i++)
	{
		//float movingSpeed = 5.f;
		//Move the cupcakes down
		m_spriteVector[i].move(0.f, m_cupcakeSpeed);
	}

}




void Cupcake::draw(sf::RenderWindow& w)
{
	for (Sprite& i : m_spriteVector)
	{
		w.draw(i);
	}

}

void Cupcake::removeCupcake()
{
	for ( int i=0; i < m_spriteVector.size(); i++)
	{
		if (m_spriteVector[i].getGlobalBounds().top > m_screenHeight)
		{
			m_spriteVector.erase(m_spriteVector.begin() + i);
			
		}
	}
}







