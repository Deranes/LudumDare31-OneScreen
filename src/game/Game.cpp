#include "Game.h"

#include <math.h>
#include "../asset/RoomLayouts.h"

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

	RoomLayouts roomLayouts;

	for ( int y = 0; y < GAME_ROOMS_Y; ++y )
	{
		for ( int x = 0; x < GAME_ROOMS_X; ++x )
		{
				Room* newRoom = new Room();
				newRoom->Initialize( roomLayouts.GetLayouts()[ y * GAME_ROOMS_X + x] );

				newRoom->SetPosition		( vec2( 0.5f + x, 0.5f + y ) * distBetweenRooms );
				newRoom->SetSize			( vec2( window->getSize().x, window->getSize().y ) );
				newRoom->SetScale			( ROOM_SCALE_SMALL );

				m_Rooms.push_back( newRoom );
		}
	}

	m_Rooms[m_ActiveRoomIndex]->SetScale( ROOM_SCALE_BIG );

	m_Player.Initialize( glm::vec2( -720.0f, 0.0f ) );
	m_Rooms[m_ActiveRoomIndex]->PlayerEntered( &m_Player );
}

void Game::Update( float deltaTime )
{
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Escape ) )
	{
		m_Window->close();
	}

	m_Player.Update( deltaTime );

	for ( auto& room : m_Rooms )
	{
		room->Update( deltaTime );
	}

	const float transitionAmount = m_Rooms[m_ActiveRoomIndex]->GetOutTransitionAmount();
	if ( transitionAmount > 0.0f )
	{
		m_RoomTransition		= transitionAmount;
		m_NextActiveRoomIndex	= m_ActiveRoomIndex + m_Rooms[m_ActiveRoomIndex]->GetDirectionToNextRoom().x + GAME_ROOMS_X * m_Rooms[m_ActiveRoomIndex]->GetDirectionToNextRoom().y;
		
		if ( m_Rooms[m_ActiveRoomIndex]->GetEnteredNextRoom() )
		{
			m_Rooms[m_ActiveRoomIndex]->PlayerLeft();

			m_Player.SetPosition( m_Player.GetPosition() + vec2( -1500.0f * m_Rooms[m_ActiveRoomIndex]->GetDirectionToNextRoom().x, -900.0f * m_Rooms[m_ActiveRoomIndex]->GetDirectionToNextRoom().y ) );

			int temp				= m_ActiveRoomIndex;
			m_ActiveRoomIndex		= m_NextActiveRoomIndex;
			m_NextActiveRoomIndex	= temp;

			m_Rooms[m_ActiveRoomIndex]->PlayerEntered( &m_Player );
		}
	}

	if ( m_RoomTransition > 0.0f )
	{
		const float transitionDone = 1.0f - m_RoomTransition;
		const float transitionLeft = m_RoomTransition;
		m_Rooms[m_ActiveRoomIndex]->SetScale( transitionDone * ROOM_SCALE_SMALL + transitionLeft * ROOM_SCALE_BIG );
		m_Rooms[m_NextActiveRoomIndex]->SetScale( transitionDone * ROOM_SCALE_BIG + transitionLeft * ROOM_SCALE_SMALL );

		for ( int i = 0; i < m_Rooms.size(); ++i )
		{
			vec2 prevPosition, nextPosition;
			this->RoomPlacement( i, m_ActiveRoomIndex, prevPosition );
			this->RoomPlacement( i, m_NextActiveRoomIndex, nextPosition );
			m_Rooms[i]->SetPosition( (transitionDone * nextPosition + transitionLeft * prevPosition) + ((0.5f * m_Rooms[i]->GetScale()) * m_Rooms[i]->GetSize()) );
		}
	}
}

void Game::Draw()
{
	for ( auto& room : m_Rooms )
	{
		room->Draw( m_Window );
	}
}

void Game::RoomPlacement( int roomIndex, int activeRoomIndex, glm::vec2& position )
{
	const vec2 windowSize		= vec2( m_Window->getSize().x, m_Window->getSize().y );
	const vec2 smallRoomSize	= ROOM_SCALE_SMALL * windowSize;
	const vec2 bigRoomSize		= ROOM_SCALE_BIG * windowSize;
	const vec2 bigSmallDiffSize	= bigRoomSize - smallRoomSize;

	int x = roomIndex % GAME_ROOMS_X, activeX = activeRoomIndex % GAME_ROOMS_X;
	int y = roomIndex / GAME_ROOMS_X, activeY = activeRoomIndex / GAME_ROOMS_X;

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

	position = screenPosition;
}