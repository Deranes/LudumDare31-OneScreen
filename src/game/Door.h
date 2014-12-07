#pragma once

#include <glm/glm.hpp>

#define DOOR_MAX_DIST	300.0f
#define DOOR_MIN_DIST	50.0f

class Door
{
public:
	void				Initialize				( const glm::ivec2& direction, const glm::vec2& position, const glm::vec2& size );
	void				Update					( const glm::vec2& playerPosition );
	
	float				GetOutTransitionAmount	() const;
	const glm::ivec2&	GetDirectionToNextRoom	() const;

private:
	glm::vec2			m_Position				= glm::vec2( 0.0f );
	glm::ivec2			m_DirectionToNextRoom	= glm::ivec2( 0 );
	float				m_OutTransitionAmount	= 0.0f;
};