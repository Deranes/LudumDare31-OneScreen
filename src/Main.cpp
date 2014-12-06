#include <SFML/Graphics.hpp>
#include "utility/PlatformDefinitions.h"
#include "game/Game.h"

int main()
{
	#ifdef WINDOWS_DEBUG
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	//_CrtSetBreakAlloc( 2704 ); //Insert allocation numbers here to invoke a break at that point
	#endif

	sf::RenderWindow window( sf::VideoMode(1600, 900), "Ola Enberg - Ludum Dare 31 - Entire Game on One Screen" );

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

		window.clear( sf::Color::Black );
		game.Draw();
		window.display();
	}

	return 0; // EXIT_SUCCESS
};