#include "Room.h"

#include <string>
#include <cassert>

using glm::vec2;

void Room::Initialize( const std::string& layout )
{
	assert( layout.size() == 15 * 9 );

	for ( int i = 0; i < layout.size(); ++i )
	{
		switch ( layout[i] )
		{
		case 'N':
			Wall wall;
			wall.SetSize( vec2( 100.0f ) );
			wall.SetColor( sf::Color::Blue );
			wall.SetPosition( (vec2( i % 15, i / 15 ) * wall.GetSize()) - vec2( 700.0f, 400.0f ) );
			m_Walls.push_back( wall );
			break;
		}
	}
}

void Room::Update( float deltaTime )
{
	if ( m_Player )
	{
		for ( auto& wall : m_Walls )
		{
			const vec2 toPlayer = m_Player->GetPosition() - wall.GetPosition();

			if ( glm::abs( toPlayer.y ) < glm::abs( toPlayer.x ) )
			{
				if ( toPlayer.x < 0.0f )
				{
					float playerRight	= m_Player->GetPosition().x + (0.5f * m_Player->GetSize().x);
					float wallLeft		= wall.GetPosition().x - (0.5f * wall.GetSize().x);
					float depth			= playerRight - wallLeft;
					if ( depth >= 0.0f && glm::abs( toPlayer.y ) <= 0.5f * (m_Player->GetSize().y + wall.GetSize().y) )
					{
						m_Player->GetEditablePosition().x -= depth;
					}
				}
				else if ( toPlayer.x > 0.0f )
				{
					float playerLeft	= m_Player->GetPosition().x - (0.5f * m_Player->GetSize().x);
					float wallRight		= wall.GetPosition().x + (0.5f * wall.GetSize().x);
					float depth			= wallRight - playerLeft;
					if ( depth >= 0.0f && glm::abs( toPlayer.y ) <= 0.5f * (m_Player->GetSize().y + wall.GetSize().y) )
					{
						m_Player->GetEditablePosition().x += depth;
					}
				}
			}
			else
			{
				if ( toPlayer.y < 0.0f )
				{
					float playerBottom	= m_Player->GetPosition().y + (0.5f * m_Player->GetSize().y);
					float wallTop		= wall.GetPosition().y - (0.5f * wall.GetSize().y);
					float depth			= playerBottom - wallTop;
					if ( depth >= 0.0f && glm::abs( toPlayer.x ) <= 0.5f * (m_Player->GetSize().x + wall.GetSize().x) )
					{
						m_Player->GetEditablePosition().y -= depth;
						m_Player->StopFalling();
					}
				}
				else if ( toPlayer.y > 0.0f )
				{
					float playerTop		= m_Player->GetPosition().y - (0.5f * m_Player->GetSize().y);
					float wallBottom	= wall.GetPosition().y + (0.5f * wall.GetSize().y);
					float depth			= wallBottom - playerTop;
					if ( depth >= 0.0f && glm::abs( toPlayer.x ) <= 0.5f * (m_Player->GetSize().x + wall.GetSize().x) )
					{
						m_Player->GetEditablePosition().y += depth;
						m_Player->StopFalling();
					}
				}
			}
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