#include "Entity.h"

using glm::vec2;

void Entity::Update( float deltaTime )
{

}

void Entity::Draw( sf::RenderWindow* window )
{
	Entity::Draw( window, vec2( 0.0f ), 1.0f );
}

void Entity::Draw( sf::RenderWindow* window, const glm::vec2& position, float scale )
{
	vec2	drawPosition	= position + scale * m_Position;
	float	drawScale		= m_Scale * scale;

	sf::RectangleShape rectangle;
	rectangle.setFillColor	( m_Color );
	rectangle.setPosition	( sf::Vector2f( drawPosition.x,	drawPosition.y	) );
	rectangle.setSize		( sf::Vector2f( m_Size.x,		m_Size.y		) );
	rectangle.setScale		( sf::Vector2f( drawScale,		drawScale		) );
	rectangle.setOrigin		( 0.5f * rectangle.getSize() );
	rectangle.setRotation	( m_Rotation );

	window->draw( rectangle );
}

const glm::vec2& Entity::GetPosition() const
{
	return m_Position;
}

glm::vec2& Entity::GetEditablePosition()
{
	return m_Position;
}

const glm::vec2& Entity::GetSize() const
{
	return m_Size;
}

float Entity::GetScale() const
{
	return m_Scale;
}

sf::Color Entity::GetColor() const
{
	return m_Color;
}

void Entity::SetPosition( const glm::vec2& newPosition )
{
	m_Position = newPosition;
}

void Entity::SetSize( const glm::vec2& newSize )
{
	m_Size = newSize;
}

void Entity::SetScale( float newScale )
{
	m_Scale = newScale;
}

void Entity::SetColor( const sf::Color newColor )
{
	m_Color = newColor;
}