#include "Room.h"

#include <string>
#include <cassert>

using glm::vec2;

void Room::Initialize( const std::string& layout )
{
	//std::string room0 = "NNNNNNNNNNNNNNNN.............NN.............NN.............NN..............N............NNN...........NNNN..........NNNNNNNNNNNNNNNNNNN";
	assert( layout.size() == 15 * 9 );

	m_Walls.resize( layout.size() );
	for ( int i = 0; i < m_Walls.size(); ++i )
	{
		m_Walls[i].SetSize( vec2( 100.0f ) );
		m_Walls[i].SetColor( sf::Color::Black );
	}

	for ( int i = 0; i < layout.size(); ++i )
	{
		switch ( layout[i] )
		{
		case 'N':
			m_Walls[i].SetPosition( vec2( i % 15, i / 15 ) * m_Walls[i].GetSize() );
			break;
		}
	}
}

void Room::Draw( sf::RenderWindow* window )
{
	Entity::Draw( window );

	for ( auto& wall : m_Walls )
	{
		wall.Draw( window, m_Position, m_Scale );
	}

	if ( m_Player )
	{
		m_Player->Draw( window, m_Position, m_Scale );
	}
}

void Room::PlayerEntered( Player* player )
{
	m_Player = player;
}

void Room::PlayerLeft()
{
	m_Player = nullptr;
}