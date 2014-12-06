#include "Game.h"

using glm::vec2;

Game::~Game()
{
	for ( auto& room : m_Rooms )
	{
		delete room;
	}
}

void Game::Intialize( sf::RenderWindow* window )
{
	m_Window = window;

	vec2 distBetweenRooms( window->getSize().x / static_cast<float>(GAME_ROOMS_X),
							window->getSize().y / static_cast<float>(GAME_ROOMS_Y) );

	for ( int y = 0; y < GAME_ROOMS_Y; ++y )
	{
		for ( int x = 0; x < GAME_ROOMS_X; ++x )
		{
				Room* newRoom				= new Room();
				newRoom->SetTargetPosition	( vec2( 0.5f + x, 0.5f + y ) * distBetweenRooms );
				newRoom->SetPosition		( newRoom->GetTargetPosition() );
				newRoom->SetSize			( vec2( ROOM_SIZE_X, ROOM_SIZE_Y ) );
				newRoom->SetRadius			( 0.5f * glm::length( newRoom->GetSize() ) );
				newRoom->SetScale			( 0.1f );

				m_Rooms.push_back( newRoom );
		}
	}
}

void Game::Update( float deltaTime )
{
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Escape ) )
	{
		m_Window->close();
	}

	m_Rooms[7]->SetScale( glm::min( 1.0f, m_Rooms[7]->GetScale() + 0.1f * deltaTime) );

	// Move all rooms towards their target destination.
	for ( auto& room : m_Rooms )
	{
		room->SetPosition( room->GetPosition() + deltaTime * (room->GetTargetPosition() - room->GetPosition()) );
	}

	// Keep rooms seperated.
	vec2 collisioNormal( 0.0f );
	for ( auto a = m_Rooms.begin(); a != m_Rooms.end(); ++a )
	{
		for ( auto b = a+1; b != m_Rooms.end(); ++b )
		{
			if ( CollisionTest( *a, *b, collisioNormal ) )
			{
				(*a)->SetPosition( (*a)->GetPosition() + 0.8f * collisioNormal );
				(*b)->SetPosition( (*b)->GetPosition() - 0.8f * collisioNormal );
			}
		}
	}

	for ( auto& room : m_Rooms )
	{
		room->Update( deltaTime );
	}
}

void Game::Draw()
{
	for ( auto& room : m_Rooms )
	{
		room->Draw( m_Window );
	}
}

bool Game::CollisionTest( Room* a, Room* b, glm::vec2& penetration )
{
	const vec2	distance	= a->GetPosition() - b->GetPosition();
	const float distSqrd	= glm::dot( distance, distance );

	const float combRadius	= a->GetScale() * a->GetRadius() + b->GetScale() * b->GetRadius();
	const float	radiusSqrd	= combRadius * combRadius;

	if ( distSqrd <= radiusSqrd )
	{
		penetration = (combRadius - glm::length( distance )) * glm::normalize( distance );
		return true;
	}
	return false;
}