#pragma once

#include <glm/glm.hpp>
#include <SFML/Graphics.hpp>

class Entity
{
public:
	virtual void				Update				( float deltaTime );
	virtual void				Draw				( sf::RenderWindow* window );
	virtual void				Draw				( sf::RenderWindow* window, const glm::vec2& position, float scale );

	virtual const glm::vec2&	GetPosition			() const;
	virtual glm::vec2&			GetEditablePosition	();
	virtual const glm::vec2&	GetSize				() const;
	virtual float				GetScale			() const;
	virtual sf::Color			GetColor			() const;

	virtual void				SetPosition			( const glm::vec2& newPosition );
	virtual void				SetSize				( const glm::vec2& newSize );
	virtual void				SetScale			( float newScale );
	virtual void				SetColor			( const sf::Color newColor );

protected:
	glm::vec2					m_Position			= glm::vec2( 0.0f );
	glm::vec2					m_Size				= glm::vec2( 1.0f );
	float						m_Scale				= 1.0f;
	sf::Color					m_Color				= sf::Color::White;
};