#include "RoomLayouts.h"

/*
N.............N N.............N NNNNNNNNNNNNNNN NNNNNNNNNNNNNNN
N.............N N.............N N.............N N.............N
N.............N N.............N N..........NN.N N...NNNNNNNNN.N
N.............N N.............N N...........N.N NNN...N....N..N
N.............> <.............> <...N...N...N.> <.NNN.N.N.NN.NN
NNNNNNNNNNNNNNN NNN.........NNN N...N...N...N.N N.N...N.N..N..N
NNNNNNNNNNNNNNN NNNN.......NNNN NN............N N.NNN.N.N.NNN.N
NNNNNNNNNNNNNNN NNNNN.....NNNNN NNN...........N N.....N.N.....N
NNNNNNNNNNNNNNN NNNNNNNNNNNNNNN NNNNNNNNNNNNNNN NNNNNNNvNNNNNNN

NNNNNNNNNNNNNNN NNNNNNNNNNNNNNN NNNNNNNNNNNNNNN NNNNNNN^NNNNNNN
N.............N N.............N N.............N N.............N
N.............N N.............N N.............N N.............N
N.............N N.............N N.............N N.............N
N.....9.......> <......8......> <......7......N N......4......N
N.............N N.............N N.............N N.............N
N.............N N.............N N.............N N.............N
N.............N N.............N N.............N N.............N
NNNNNNNvNNNNNNN NNNNNNNNNNNNNNN NNNNNNNvNNNNNNN NNNNNNNvNNNNNNN

NNNNNNN^NNNNNNN NNNNNNNNNNNNNNN NNNNNNN^NNNNNNN NNNNNNN^NNNNNNN
N.............N N.............N N.............N N.............N
N.............N N.............N N.........6...N N.............N
N.............N N.............N NNN...........N N.............N
N.....10......N N.....13......> <.NNNNNN......> <......5......N
N.............N N.............N N......NNNNNNNN N.............N
N.............N N.............N N....14.......N N.............N
N.............N N.............N N.............N N.............N
NNNNNNNvNNNNNNN NNNNNNNvNNNNNNN NNNNNNNvNNNNNNN NNNNNNNNNNNNNNN

NNNNNNN^NNNNNNN NNNNNNN^NNNNNNN NNNNNNN^NNNNNNN NNNNNNNNNNNNNNN
N.............N N.............N N.............N N.............N
N.............N N.............N N.............N N.............N
N.............N N.............N N.............N N.............N
N.....11......> <.....12......N N.....15......> <.....16......N
N.............N N.............N N.............N N.............N
N.............N N.............N N.............N N.............N
N.............N N.............N N.............N N.............N
NNNNNNNNNNNNNNN NNNNNNNNNNNNNNN NNNNNNNNNNNNNNN NNNNNNNNNNNNNNN
*/

RoomLayouts::RoomLayouts()
{
	m_Layouts.push_back( "N.............NN.............NN.............NN.............NN.............>NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN" );
	m_Layouts.push_back( "N.............NN.............NN.............NN.............N<.............>NNN.........NNNNNNN.......NNNNNNNNN.....NNNNNNNNNNNNNNNNNNNN" );
	m_Layouts.push_back( "N.............NN..........NN.NN...........N.NN...N...N...N.N<...N...N...N.>NN..N...N...N.NNNN...........NNNN...........NNNNNNNNNNNNNNNN" );
	m_Layouts.push_back( "NNNNNNNNNNNNNNNN.............NN...NNNNNNNNN.NNNN...N....N..N<.NNN.N.N.NN.NNN.N...N.N..N..NN.NNN.N.N.NNN.NN.....N.N.....NNNNNNNNvNNNNNNN" );

	for ( int i = static_cast<int>(m_Layouts.size()); i < 16; ++i )
	{
		m_Layouts.push_back("NNNNNNN^NNNNNNNN.............NN.............NN.............N<.............>N.............NN.............NN.............NNNNNNNNvNNNNNNN");
	}
}

const std::vector<std::string>& RoomLayouts::GetLayouts() const
{
	return m_Layouts;
}