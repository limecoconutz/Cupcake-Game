#include "Player.h"
#include "TextureHolder.h"

using namespace sf;

Player::Player()
{
	m_points = 0;
	m_health = 20;
	m_dead = false;

	
}

Player::~Player()
{

}





bool Player::isAlive()
{
	if (m_health <= 0)
	{
		m_dead = true;
	}
	else
	{
		m_dead = false;
	}

	return m_dead;
	
}
