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
				Room* newRoom = new Room();

				newRoom->SetPosition( vec2( 0.5f + x, 0.5f + y ) * distBetweenRooms );

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