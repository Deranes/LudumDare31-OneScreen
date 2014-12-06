#include <SFML/Graphics.hpp>
#include "game/Game.h"

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 4;

	sf::RenderWindow window( sf::VideoMode(1600, 900), "Ola Enberg - Ludum Dare 31 - Entire Game on One Screen", sf::Style::Default, settings );

	Game game;
	game.Intialize( &window );

	sf::Clock deltaClock;

	while ( window.isOpen() )
	{
		sf::Event event;
		while ( window.pollEvent( event ) )
		{
			if ( event.type == sf::Event::Closed )
			{
				window.close();
			}
		}

		sf::Time deltaTime = deltaClock.restart();

		game.Update( deltaTime.asSeconds() );

		window.clear( sf::Color::White );
		game.Draw();
		window.display();
	}

	return 0; // EXIT_SUCCESS
};