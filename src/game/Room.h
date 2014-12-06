#pragma once

#include <glm/glm.hpp>
#include <SFML/Graphics.hpp>

#define ROOM_SIZE_X		720
#define ROOM_SIZE_Y		720

class Room
{
public:
	void					Update				( float deltaTime );
	void					Draw				( sf::RenderWindow* window );

	const glm::vec2&		GetPosition			() const;
	const glm::vec2&		GetSize				() const;
	float					GetRadius			() const;
	float					GetScale			() const;
	const glm::vec2&		GetTargetPosition	() const;

	void					SetPosition			( const glm::vec2& newPosition );
	void					SetSize				( const glm::vec2& newSize );
	void					SetRadius			( float newRadius );
	void					SetScale			( float newScale );
	void					SetTargetPosition	( const glm::vec2& newTargetPosition );

private:
	glm::vec2				m_Position			= glm::vec2( 0.0f );
	glm::vec2				m_Size				= glm::vec2( 1.0f );
	float					m_Radius			= 1.0f;
	float					m_Scale				= 1.0f;

	glm::vec2				m_TargetPosition	= glm::vec2( 0.0f );
};