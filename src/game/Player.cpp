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
		m_Position.x += deltaTime * PLAYER_WALK_SPEED;
		m_RotateRight = true;
	}
	if ( Keyboard::isKeyPressed( Keyboard::A ) )
	{
		m_Position.x -= deltaTime * PLAYER_WALK_SPEED;
		m_RotateRight = false;
	}
	if ( Keyboard::isKeyPressed( Keyboard::Space ) )
	{
		if ( m_CanJump )
		{
			m_FallSpeed		= -PLAYER_JUMP_POWER;
			m_JumpTimeLeft	= PLAYER_JUMP_TIME - deltaTime;
		}
		else if ( m_JumpTimeLeft > 0.0f )
		{
			m_FallSpeed		= -PLAYER_JUMP_POWER;
			m_JumpTimeLeft -= deltaTime;
		}
	}
	else
	{
		m_JumpTimeLeft = 0.0f;
	}

	if ( m_RotateRight )
		m_Rotation = m_CanJump ? 0.0f : m_Rotation + PLAYER_ROT_SPEED * deltaTime;
	else
		m_Rotation = m_CanJump ? 0.0f : m_Rotation - PLAYER_ROT_SPEED * deltaTime;

	m_FallSpeed += deltaTime * PLAYER_GRAVITY;
	m_Position.y += deltaTime * m_FallSpeed;

	m_CanJump = false;
}

void Player::StopFalling()
{
	m_FallSpeed = 0.0f;
	m_CanJump	= true;
}