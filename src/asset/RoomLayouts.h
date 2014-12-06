#pragma once

#include <vector>

class RoomLayouts
{
public:
										RoomLayouts();

	const std::vector<std::string>&		GetLayouts() const;

private:
	std::vector<std::string>			m_Layouts;
};