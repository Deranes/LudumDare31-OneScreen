#include "Room.h"

void Room::Update( float deltaTime )
{

}

void Room::Draw( sf::RenderWindow* window )
{
	sf::RectangleShape rectangle;
	rectangle.setFillColor	( sf::Color::Blue );
	rectangle.setPosition	( sf::Vector2f( m_Position.x,	m_Position.y	) );
	rectangle.setSize		( sf::Vector2f( m_Size.x,		m_Size.y		) );
	rectangle.setScale		( sf::Vector2f( m_Scale,		m_Scale			) );
	rectangle.setOrigin		( 0.5f * rectangle.getSize() );

	window->draw( rectangle );
}

const glm::vec2& Room::GetPosition() const
{
	return m_Position;
}

const glm::vec2& Room::GetSize() const
{
	return m_Size;
}

float Room::GetRadius() const
{
	return m_Radius;
}

float Room::GetScale() const
{
	return m_Scale;
}

const glm::vec2& Room::GetTargetPosition() const
{
	return m_TargetPosition;
}

void Room::SetPosition( const glm::vec2& newPosition )
{
	m_Position = newPosition;
}

void Room::SetSize( const glm::vec2& newSize )
{
	m_Size = newSize;
}

void Room::SetRadius( float newRadius )
{
	m_Radius = newRadius;
}

void Room::SetScale( float newScale )
{
	m_Scale = newScale;
}

void Room::SetTargetPosition( const glm::vec2& newTargetPosition )
{
	m_TargetPosition = newTargetPosition;
}