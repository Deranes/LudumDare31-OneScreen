#pragma once

#include "Entity.h"

class Ball : public Entity
{
public:
	void			Update		( float deltaTime ) override;

	glm::vec2		Velocity	= glm::vec2( 0.0f, 0.0f );
};