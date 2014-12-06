#include "Game.h"

void Game::Intialize( sf::RenderWindow* window )
{
	m_Window = window;

	//sf::CircleShape shape(100.f);
	//shape.setFillColor(sf::Color::Green);
}

void Game::Update( float deltaTime )
{
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Escape ) )
	{
		m_Window->close();
	}
}

void Game::Draw()
{
	//m_Window.draw(shape);
}