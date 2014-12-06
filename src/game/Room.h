#pragma once

#include "Entity.h"

#include <vector>
#include "Wall.h"

class Room : public Entity
{
public:
	void				Initialize		( const std::string& layout );
	void				Draw			( sf::RenderWindow* window ) override;

private:
	std::vector<Wall>	m_Walls;
};