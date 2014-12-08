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

	if ( !m_CanJump )
	{
		if ( glm::abs( m_Rotation ) < 360.0f )
		{
			if ( m_RotateRight )
				m_Rotation += PLAYER_ROT_SPEED * deltaTime;
			else
				m_Rotation -= PLAYER_ROT_SPEED * deltaTime;
		}
	}
	else
	{
		m_Rotation = 0.0f;
	}
	 
	m_FallSpeed += deltaTime * PLAYER_GRAVITY;
	m_Position.y += deltaTime * m_FallSpeed;

	m_CanJump = false;
}

void Player::StopFalling()
{
	m_FallSpeed = 0.0f;
	m_CanJump	= true;
}

void Player::Jump( float power )
{
	m_FallSpeed = -power;
}

void Player::Respawn()
{
	m_Position	= m_RespawnPos;
	m_FallSpeed	= 0.0f;
	m_CanJump	= false;
}

void Player::SetRespawnPos( const glm::vec2& newRespawnPos )
{
	m_RespawnPos = newRespawnPos;
}