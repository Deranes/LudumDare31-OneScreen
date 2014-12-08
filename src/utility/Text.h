#pragma once

#include <SFML/Graphics.hpp>
#include <glm/glm.hpp>
#include <string>

class Text
{
public:
	void			Draw( sf::RenderWindow* window, const glm::vec2& position, float scale );

	sf::Font		m_Font;
	std::string		m_Text;
	glm::vec2		m_Position;
	int				m_FontSize;
};