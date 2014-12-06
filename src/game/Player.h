#pragma once

#include "Entity.h"

#define GRAVITY		500.0f

class Player : public Entity
{
public:
	void				Initialize		( const glm::vec2& position );

	void				Update			( float deltaTime ) override;

private:
	float				m_FallSpeed		= 0.0f;
};