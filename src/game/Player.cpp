#include "Player.h"

using glm::vec2;
using sf::Keyboard;

void Player::Initialize( const glm::vec2& position )
{
	m_Position	= position;
	m_Size		= vec2( 60.0f );
	m_Color		= sf::Color::Red;
}

void Player::Update( float deltaTime )
{
	if ( Keyboard::isKeyPressed( Keyboard::D ) )
	{
		m_Position.x += deltaTime * 400.0f;
	}
	if ( Keyboard::isKeyPressed( Keyboard::A ) )
	{
		m_Position.x -= deltaTime * 400.0f;
	}
	if ( Keyboard::isKeyPressed( Keyboard::Space ) )
	{
		m_FallSpeed = -400.0f;
	}

	m_FallSpeed += deltaTime * GRAVITY;
	m_Position.y += deltaTime * m_FallSpeed;
}

void Player::StopFalling()
{
	m_FallSpeed = 0.0f;
}