#pragma once
#include "Engine.h"

void Engine::updateMousePosition()
{
	m_mousePosition_Window = sf::Mouse::getPosition(m_Window);
	m_mousePosition = m_Window.mapPixelToCoords(m_mousePosition_Window);
	
}