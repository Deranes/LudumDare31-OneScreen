#include "Door.h"

using glm::vec2;

void Door::Initialize( const glm::ivec2& direction, const glm::vec2& position, const glm::vec2& size )
{
	m_DirectionToNextRoom	= direction;
	m_Position				= position + 0.5f * vec2( direction.x * size.x, direction.y * size.y );
}

void Door::Update( const glm::vec2& playerPosition )
{
	float distance = glm::length( playerPosition - m_Position );
	if ( distance >= DOOR_MAX_DIST )
	{
		m_OutTransitionAmount = 0.0f;
	} 
	else if ( distance <= DOOR_MIN_DIST )
	{
		m_OutTransitionAmount = 0.5f;
	}
	else
	{
		m_OutTransitionAmount = 0.5f + 0.5f * (distance - DOOR_MIN_DIST) / (DOOR_MAX_DIST - DOOR_MIN_DIST);
	}
}

float Door::GetOutTransitionAmount() const
{
	return m_OutTransitionAmount;
}

const glm::ivec2& Door::GetDirectionToNextRoom() const
{
	return m_DirectionToNextRoom;
}