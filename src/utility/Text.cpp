#include "Text.h"

void Text::Draw( sf::RenderTexture* window, const glm::vec2& position, float scale )
{
	static sf::Text text;
	text.setColor( sf::Color::Black );
	text.setStyle(sf::Text::Bold);
	text.setFont( m_Font );
	text.setCharacterSize( m_FontSize );
	text.setPosition( position.x + scale * m_Position.x, position.y + scale * m_Position.y );
	text.setScale( scale, scale );
	text.setString( m_Text );
	text.setOrigin( 0.5f * text.getLocalBounds().width, 0.5f * text.getLocalBounds().height );

	window->draw( text );
}