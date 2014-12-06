#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "Room.h"

#define GAME_ROOMS_X		4
#define GAME_ROOMS_Y		4
#define ROOM_SCALE_BIG		0.58f
#define ROOM_SCALE_SMALL	0.14f

class Game
{
public:
						~Game			();

	void				Intialize		( sf::RenderWindow* window );
	void				Update			( float deltaTime );
	void				Draw			();

private:
	sf::RenderWindow*	m_Window;
	std::vector<Room*>	m_Rooms;
	int					m_ActiveRoomIndex	= 6;
};