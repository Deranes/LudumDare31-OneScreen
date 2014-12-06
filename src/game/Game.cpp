#include "Game.h"

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

	Room* firstRoom = new Room();
	m_Rooms.push_back( firstRoom );
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