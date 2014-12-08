#pragma once

#include "Entity.h"

#include <vector>
#include "Wall.h"
#include "Player.h"
#include "Door.h"
#include "JumpPlate.h"
#include "Ball.h"

class Room : public Entity
{
public:
	void					Initialize				( const std::string& layout );
	void					Update					( float deltaTime ) override;
	void					Draw					( sf::RenderWindow* window ) override;

	void					PlayerEntered			( Player* player );
	void					PlayerLeft				();

	float					GetOutTransitionAmount	() const;
	const glm::ivec2&		GetDirectionToNextRoom	() const;
	bool					GetEnteredNextRoom		() const;

private:
	void					PlayerVsWall			();
	void					PlayerVsJumpPlate		();
	void					PlayerVsBall			();
	void					BallVsWall				();

	std::vector<Wall>		m_Walls;
	std::vector<Door>		m_Doors;
	std::vector<JumpPlate>	m_JumpPlates;
	std::vector<Ball>		m_Balls;
	Player*					m_Player				= nullptr;
	float					m_OutTransitionAmount	= 0.0f;
	glm::ivec2				m_DirectionToNextRoom	= glm::ivec2( 0, 0 );
	bool					m_EnteredNextRoom		= false;
};