#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "Room.h"

class Game
{
public:
						~Game();

	void				Intialize( sf::RenderWindow* window );
	void				Update( float deltaTime );
	void				Draw();

private:
	sf::RenderWindow*	m_Window;
	std::vector<Room*>	m_Rooms;	
};