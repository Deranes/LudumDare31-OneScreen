#pragma once

#include <glm/glm.hpp>
#include <SFML/Graphics.hpp>

#define ROOM_SIZE_X		150
#define ROOM_SIZE_Y		100

class Room
{
public:
	void					Update( float deltaTime );
	void					Draw( sf::RenderWindow* window );

	const glm::vec2&		GetPosition		() const;
	const glm::vec2&		GetSize			() const;
	float					GetScale		() const;

	void					SetPosition		( const glm::vec2& newPosition );
	void					SetSize			( const glm::vec2& newSize );
	void					SetScale		( float newScale );

private:
	glm::vec2				m_Position		= glm::vec2( 0.0f );
	glm::vec2				m_Size			= glm::vec2( ROOM_SIZE_X, ROOM_SIZE_Y );
	float					m_Scale			= 1.0f;
};