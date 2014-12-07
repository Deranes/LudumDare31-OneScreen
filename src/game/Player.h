#pragma once

#include "Entity.h"

#define PLAYER_WALK_SPEED	290.0f
#define PLAYER_GRAVITY		2500.0f
#define PLAYER_JUMP_POWER	600.0f
#define PLAYER_JUMP_TIME	0.27f

class Player : public Entity
{
public:
	void				Initialize		( const glm::vec2& position );
	void				Update			( float deltaTime ) override;
	void				StopFalling		();

private:
	float				m_FallSpeed		= 0.0f;
	bool				m_CanJump		= false;
	float				m_JumpTimeLeft	= 0.0f;
};