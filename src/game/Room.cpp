#include "Room.h"

using glm::vec2;

void Room::Initialize()
{
	m_Walls.resize( 1 );
	m_Walls[0].SetPosition( vec2( 100.0f ) );
	m_Walls[0].SetSize( vec2( 100.0f ) );
	m_Walls[0].SetColor( sf::Color::Blue );
}

void Room::Draw( sf::RenderWindow* window )
{
	Entity::Draw( window );

	for ( auto& wall : m_Walls )
	{
		wall.Draw( window, m_Position, m_Scale );
	}
}