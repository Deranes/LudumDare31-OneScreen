#pragma once

#include "Entity.h"

#define GRAVITY		1900.0f

class Player : public Entity
{
public:
	void				Initialize		( const glm::vec2& position );
	void				Update			( float deltaTime ) override;
	void				StopFalling		();

private:
	float				m_FallSpeed		= 0.0f;
};