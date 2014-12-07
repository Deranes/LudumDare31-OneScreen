#pragma once

#include "Entity.h"

#include <vector>
#include "Wall.h"
#include "Player.h"
#include "Door.h"

class Room : public Entity
{
public:
	void				Initialize				( const std::string& layout );
	void				Update					( float deltaTime ) override;
	void				Draw					( sf::RenderWindow* window ) override;

	void				PlayerEntered			( Player* player );
	void				PlayerLeft				();

	float				GetOutTransitionAmount	() const;
	const glm::ivec2&	GetDirectionToNextRoom	() const;

private:
	void				PlayerVsWall			();

	std::vector<Wall>	m_Walls;
	std::vector<Door>	m_Doors;
	Player*				m_Player				= nullptr;
	float				m_OutTransitionAmount	= 0.0f;
	glm::ivec2			m_DirectionToNextRoom	= glm::ivec2( 0, 0 );
};