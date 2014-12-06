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
				newRoom->SetPosition		( vec2( 0.5f + x, 0.5f + y ) * distBetweenRooms );
				newRoom->SetSize			( vec2( window->getSize().x, window->getSize().y ) );
				newRoom->SetScale			( ROOM_SCALE_SMALL );

				m_Rooms.push_back( newRoom );
		}
	}

	m_Rooms[m_ActiveRoomIndex]->SetScale( ROOM_SCALE_BIG );
}

void Game::Update( float deltaTime )
{
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Escape ) )
	{
		m_Window->close();
	}

	static float timer = 1.0f;
	timer -= deltaTime;
	if ( timer <= 0.0f )
	{
		m_Rooms[m_ActiveRoomIndex]->SetScale( ROOM_SCALE_SMALL );
		m_ActiveRoomIndex = (m_ActiveRoomIndex+1) % m_Rooms.size();
		m_Rooms[m_ActiveRoomIndex]->SetScale( ROOM_SCALE_BIG );
		timer = 1.0f;
	}

	{
		const vec2 windowSize		= vec2( m_Window->getSize().x, m_Window->getSize().y );
		const vec2 smallRoomSize	= ROOM_SCALE_SMALL * windowSize;
		const vec2 bigRoomSize		= ROOM_SCALE_BIG * windowSize;
		const vec2 bigSmallDiffSize	= bigRoomSize - smallRoomSize;

		int x = 0, activeX = m_ActiveRoomIndex % GAME_ROOMS_X;
		int y = 0, activeY = m_ActiveRoomIndex / GAME_ROOMS_X;
		for ( auto& room : m_Rooms )
		{
			 vec2 screenPosition(	x * smallRoomSize.x + (x <= activeX ? 0 : bigSmallDiffSize.x),
									y * smallRoomSize.y + (y <= activeY ? 0 : bigSmallDiffSize.y) );

			if ( x == activeX && y != activeY )
			{
				screenPosition.x += 0.5f * bigSmallDiffSize.x;
			}
			if ( y == activeY && x != activeX )
			{
				screenPosition.y += 0.5f * bigSmallDiffSize.y;
			}

			room->SetPosition( screenPosition );

			if ( ++x == GAME_ROOMS_X )
			{
				x = 0;
				++y;
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