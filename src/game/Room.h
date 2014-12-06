#pragma once

#include "Entity.h"

#include <vector>
#include "Wall.h"
#include "Player.h"

class Room : public Entity
{
public:
	void				Initialize		( const std::string& layout );
	void				Draw			( sf::RenderWindow* window ) override;

	void				PlayerEntered	( Player* player );
	void				PlayerLeft		();

private:
	std::vector<Wall>	m_Walls;
	Player*				m_Player		= nullptr;
};