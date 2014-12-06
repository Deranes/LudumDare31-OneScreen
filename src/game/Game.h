#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "Room.h"

#define GAME_ROOMS_X	5
#define GAME_ROOMS_Y	4

class Game
{
public:
						~Game			();

	void				Intialize		( sf::RenderWindow* window );
	void				Update			( float deltaTime );
	void				Draw			();

private:
	bool				CollisionTest	( Room* a, Room* b, glm::vec2& outCollisionNormal );

	sf::RenderWindow*	m_Window;
	std::vector<Room*>	m_Rooms;	
};