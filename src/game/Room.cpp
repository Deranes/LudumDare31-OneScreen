#include "Room.h"

#include <string>
#include <cassert>

using glm::vec2;
using glm::ivec2;

void Room::Initialize( const std::string& layout )
{
	assert( layout.size() == 15 * 9 );

	for ( int i = 0; i < layout.size(); ++i )
	{
		const vec2 tileSize		= vec2( 100.0f );
		const vec2 tilePosition	= (vec2( i % 15, i / 15 ) * tileSize) - vec2( 700.0f, 400.0f ); 

		switch ( layout[i] )
		{
			case 'N':
			{
				Wall wall;
				wall.SetSize( vec2( 100.0f ) );
				wall.SetColor( sf::Color::Black );
				wall.SetPosition( tilePosition );
				m_Walls.push_back( wall );
				break;
			}
			case '>':
			{
				Door door;
				door.Initialize( ivec2( 1, 0 ), tilePosition, tileSize );
				m_Doors.push_back( door );
				break;
			}
			case '<':
			{
				Door door;
				door.Initialize( ivec2( -1, 0 ), tilePosition, tileSize );
				m_Doors.push_back( door );
				break;
			}
			case 'v':
			{
				Door door;
				door.Initialize( ivec2( 0, 1 ), tilePosition, tileSize );
				m_Doors.push_back( door );
				break;
			}
			case '^':
			{
				Door door;
				door.Initialize( ivec2( 0, -1 ), tilePosition, tileSize );
				m_Doors.push_back( door );
				break;
			}
			case 'j':
			{
				JumpPlate jumpPlate;
				jumpPlate.SetPosition( vec2( tilePosition.x, tilePosition.y + 45.0f ) );
				jumpPlate.SetSize( vec2( tileSize.x, 10.0f ) );
				jumpPlate.SetColor( sf::Color::Blue );
				m_JumpPlates.push_back( jumpPlate );
				break;
			}
			case '-':
			{
				Ball ball;
				ball.SetPosition( tilePosition );
				ball.SetSize( tileSize * 0.2f );
				ball.SetColor( sf::Color::Red );
				m_Balls.push_back( ball );
				break;
			}
		}
	}
}

void Room::Update( float deltaTime )
{
	m_EnteredNextRoom		= false;
	m_OutTransitionAmount	= 0.0f;

	for ( auto& ball : m_Balls )
	{
		ball.Update( deltaTime );
	}
	BallVsWall();

	if ( m_Player )
	{

		PlayerVsWall();
		PlayerVsJumpPlate();

		for ( auto& door : m_Doors )
		{
			door.Update( m_Player->GetPosition() );
			if ( door.GetOutTransitionAmount() > m_OutTransitionAmount )
			{
				m_OutTransitionAmount	= door.GetOutTransitionAmount();
				m_DirectionToNextRoom	= door.GetDirectionToNextRoom();
				m_EnteredNextRoom		= door.GetEnteredNextRoom();
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

	for ( auto& jumpPlate : m_JumpPlates )
	{
		jumpPlate.Draw( window, m_Position, m_Scale );
	}

	for ( auto& ball : m_Balls )
	{
		ball.Draw( window, m_Position, m_Scale );
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

float Room::GetOutTransitionAmount() const
{
	return m_OutTransitionAmount;
}

const glm::ivec2& Room::GetDirectionToNextRoom() const
{
	return m_DirectionToNextRoom;
}

bool Room::GetEnteredNextRoom() const
{
	return m_EnteredNextRoom;
}

void Room::PlayerVsWall()
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
				}
			}
		}
	}
}

void Room::PlayerVsJumpPlate()
{
	for ( auto& jumpPlate : m_JumpPlates )
	{
		const vec2 toPlayer = m_Player->GetPosition() - jumpPlate.GetPosition();
		if ( toPlayer.y < 0.0f )
		{
			float playerBottom	= m_Player->GetPosition().y + (0.5f * m_Player->GetSize().y);
			float plateTop		= jumpPlate.GetPosition().y - (0.5f * jumpPlate.GetSize().y);
			float depth			= playerBottom - plateTop;
			if ( depth >= 0.0f && glm::abs( toPlayer.x ) <= 0.5f * (m_Player->GetSize().x + jumpPlate.GetSize().x) )
			{
				m_Player->GetEditablePosition().y -= depth;
				m_Player->Jump( 1650.0f );
			}
		}
	}
}

void Room::BallVsWall()
{
	for ( auto& ball : m_Balls )
	{
		for ( auto& wall : m_Walls )
		{
			const vec2 toPlayer = ball.GetPosition() - wall.GetPosition();

			if ( glm::abs( toPlayer.y ) < glm::abs( toPlayer.x ) )
			{
				if ( toPlayer.x < 0.0f )
				{
					float playerRight	= ball.GetPosition().x + (0.5f * ball.GetSize().x);
					float wallLeft		= wall.GetPosition().x - (0.5f * wall.GetSize().x);
					float depth			= playerRight - wallLeft;
					if ( depth >= 0.0f && glm::abs( toPlayer.y ) <= 0.5f * (ball.GetSize().y + wall.GetSize().y) )
					{
						ball.GetEditablePosition().x -= depth;
						ball.Velocity *= -1.0f;
					}
				}
				else if ( toPlayer.x > 0.0f )
				{
					float playerLeft	= ball.GetPosition().x - (0.5f * ball.GetSize().x);
					float wallRight		= wall.GetPosition().x + (0.5f * wall.GetSize().x);
					float depth			= wallRight - playerLeft;
					if ( depth >= 0.0f && glm::abs( toPlayer.y ) <= 0.5f * (ball.GetSize().y + wall.GetSize().y) )
					{
						ball.GetEditablePosition().x += depth;
						ball.Velocity *= -1.0f;
					}
				}
			}
			else
			{
				if ( toPlayer.y < 0.0f )
				{
					float playerBottom	= ball.GetPosition().y + (0.5f * ball.GetSize().y);
					float wallTop		= wall.GetPosition().y - (0.5f * wall.GetSize().y);
					float depth			= playerBottom - wallTop;
					if ( depth >= 0.0f && glm::abs( toPlayer.x ) <= 0.5f * (ball.GetSize().x + wall.GetSize().x) )
					{
						ball.GetEditablePosition().y -= depth;
						ball.Velocity *= -1.0f;
					}
				}
				else if ( toPlayer.y > 0.0f )
				{
					float playerTop		= ball.GetPosition().y - (0.5f * ball.GetSize().y);
					float wallBottom	= wall.GetPosition().y + (0.5f * wall.GetSize().y);
					float depth			= wallBottom - playerTop;
					if ( depth >= 0.0f && glm::abs( toPlayer.x ) <= 0.5f * (ball.GetSize().x + wall.GetSize().x) )
					{
						ball.GetEditablePosition().y += depth;
						ball.Velocity *= -1.0f;
					}
				}
			}
		}
	}
}