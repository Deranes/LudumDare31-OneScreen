#include "Room.h"

#include <string>
#include <cassert>

using glm::vec2;

/* Room 0 (0,0)
NNNNNNNNNNNNNNNN
N..............N
N..............N
N.....N....N...N
N.....N........N
N.....N........N
N..............N
N...............
NNNNNNNNNNNNNNNN
*/

void Room::Initialize()
{
	std::string room0 = "NNNNNNNNNNNNNNNNN..............NN..............NN.....N....N...NN.....N........NN.....N........NN..............NN...............NNNNNNNNNNNNNNNN";
	assert( room0.size() == 16 * 9 );

	m_Walls.resize( room0.size() );
	for ( int i = 0; i < m_Walls.size(); ++i )
	{
		m_Walls[i].SetSize( vec2( 100.0f ) );
		m_Walls[i].SetColor( sf::Color::Blue );
	}

	for ( int i = 0; i < room0.size(); ++i )
	{
		switch ( room0[i] )
		{
		case 'N':
			m_Walls[i].SetPosition( vec2( i % 16, i / 16 ) * m_Walls[i].GetSize() );
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
}