#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "Room.h"

#define GAME_ROOMS_X			4
#define GAME_ROOMS_Y			4
#define ROOM_SCALE_BIG			0.64f
#define ROOM_SCALE_SMALL		0.12f
#define ROOM_TRANSITION_TIME	0.5f

class Game
{
public:
						~Game			();

	void				Intialize		( sf::RenderWindow* window );
	void				Update			( float deltaTime );
	void				Draw			();

private:
	void				RoomPlacement	( int roomIndex, int activeRoomIndex, glm::vec2& position );

	sf::RenderWindow*	m_Window;
	std::vector<Room*>	m_Rooms;
	int					m_ActiveRoomIndex		= 0;
	int					m_PrevActiveRoomIndex	= 0;
	float				m_RoomTransitionTimer	= 0.1f;
};