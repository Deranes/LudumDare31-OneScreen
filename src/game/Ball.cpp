#include "Ball.h"

void Ball::Update( float deltaTime )
{
	m_Position += deltaTime * this->Velocity;
}