#include "RoomLayouts.h"

/*
NNNNNNNNNNNNNNN NNNNNNN.NNNNNNN NNNNNNN.NNNNNNN NNNNNNN.NNNNNNN
N.............N N.............N N.............N N.............N
N.............N N.............N N.............N N.............N
N.............N N.............N N.............N N.............N
N.............> ............... ............... ...............
NNNNNNNNNNNNNNN N.............N N.............N N.............N
NNNNNNNNNNNNNNN N.............N N.............N N.............N
NNNNNNNNNNNNNNN N.............N N.............N N.............N
NNNNNNNNNNNNNNN NNNNNNN.NNNNNNN NNNNNNN.NNNNNNN NNNNNNN.NNNNNNN

NNNNNNN.NNNNNNN NNNNNNN.NNNNNNN NNNNNNN.NNNNNNN NNNNNNN.NNNNNNN
N.............N N.............N N.............N N.............N
N.............N N.............N N.............N N.............N
N.............N N.............N N.............N N.............N
............... ............... ............... ...............
N.............N N.............N N.............N N.............N
N.............N N.............N N.............N N.............N
N.............N N.............N N.............N N.............N
NNNNNNN.NNNNNNN NNNNNNN.NNNNNNN NNNNNNN.NNNNNNN NNNNNNN.NNNNNNN

NNNNNNN.NNNNNNN NNNNNNN.NNNNNNN NNNNNNN.NNNNNNN NNNNNNN.NNNNNNN
N.............N N.............N N.............N N.............N
N.............N N.............N N.............N N.............N
N.............N N.............N N.............N N.............N
............... ............... ............... ...............
N.............N N.............N N.............N N.............N
N.............N N.............N N.............N N.............N
N.............N N.............N N.............N N.............N
NNNNNNN.NNNNNNN NNNNNNN.NNNNNNN NNNNNNN.NNNNNNN NNNNNNN.NNNNNNN

NNNNNNN.NNNNNNN NNNNNNN.NNNNNNN NNNNNNN.NNNNNNN NNNNNNN.NNNNNNN
N.............N N.............N N.............N N.............N
N.............N N.............N N.............N N.............N
N.............N N.............N N.............N N.............N
............... ............... ............... ...............
N.............N N.............N N.............N N.............N
N.............N N.............N N.............N N.............N
N.............N N.............N N.............N N.............N
NNNNNNN.NNNNNNN NNNNNNN.NNNNNNN NNNNNNN.NNNNNNN NNNNNNN.NNNNNNN
*/

RoomLayouts::RoomLayouts()
{
	//m_Layouts.push_back( "N.............NN.............NN.............NN.............NN.............>NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN" );

	for ( int i = static_cast<int>(m_Layouts.size()); i < 16; ++i )
	{
		m_Layouts.push_back("N.............NN.............NN.............NN.............N...............N.............NN.............NN.............NNNNNNNN.NNNNNNN");
	}
}

const std::vector<std::string>& RoomLayouts::GetLayouts() const
{
	return m_Layouts;
}