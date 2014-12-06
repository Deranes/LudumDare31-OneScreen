#pragma once

#include <SFML/Graphics.hpp>

class Game
{
public:
	void				Intialize( sf::RenderWindow* window );
	void				Update( float deltaTime );
	void				Draw();

private:
	sf::RenderWindow*	m_Window;
};