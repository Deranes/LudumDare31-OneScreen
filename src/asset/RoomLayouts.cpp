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
N.............N N.............N N.............N NN......NNNNNNN
N.............N N.............N N.............N NN..NNN..NNNNNN
N.............N N.............N N.............N NN.NNNN...NNNNN
N.....9.......> <......8......> <......7......> <..NNNN.......N
N.............N N.............N N.............N NNNNNNN.NNNN..N
N.............N N.............N N.............N NNNNNNN.NNNNN.N
N.............N N.............N N.............N NNNNNNN.......N
NNNNNNNvNNNNNNN NNNNNNNNNNNNNNN NNNNNNNvNNNNNNN NNNNNNNvNNNNNNN

NNNNNNN^NNNNNNN NNNNNNNNNNNNNNN NNNNNNN^NNNNNNN NNNNNNN^NNNNNNN
N.............N N.............N N.............N N.............N
N.............N N.............N N.........6...N N...NNNNNNNNNNN
N.............N N.............N NNN...........N NNN...N.....N.N
N.....10......N N.....13......> <.NNNNNN......> <..N.....N....N
N.............N N.............N N......NNNNNNNN N..NNNNNNNNNN.N
N.............N N.............N N....14.......N N.NN.......N..N
N.............N N.............N N.............N N.....NN.....NN
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
	
	m_Layouts.push_back( "NNNNNNNNNNNNNNNN.............NN.............NN.............NN.....9.......>N.............NN.............NN.............NNNNNNNNvNNNNNNN" );
	m_Layouts.push_back( "NNNNNNNNNNNNNNNN.............NN.............NN.............N<......8......>N.............NN.............NN.............NNNNNNNNNNNNNNNN" );
	m_Layouts.push_back( "NNNNNNNNNNNNNNNN.............NN.............NN.............N<......7......>N.............NN.............NN.............NNNNNNNNvNNNNNNN" );
	m_Layouts.push_back( "NNNNNNN^NNNNNNNNN......NNNNNNNNN..NNN..NNNNNNNN.NNNN...NNNNN<..NNNN.......NNNNNNNN.NNNN..NNNNNNNN.NNNNN.NNNNNNNN.......NNNNNNNNvNNNNNNN" );
	
	m_Layouts.push_back( "NNNNNNN^NNNNNNNN.............NN.............NN.............NN.....10......NN.............NN.............NN.............NNNNNNNNvNNNNNNN" );
	m_Layouts.push_back( "NNNNNNNNNNNNNNNN.............NN.............NN.............NN.....13......>N.............NN.............NN.............NNNNNNNNvNNNNNNN" );
	m_Layouts.push_back( "NNNNNNN^NNNNNNNN.............NN.........6...NNNN...........N<.NNNNNN......>N......NNNNNNNNN....14.......NN.............NNNNNNNNvNNNNNNN" );
	m_Layouts.push_back( "NNNNNNN^NNNNNNNN.............NN...NNNNNNNNNNNNNN...N.....N.N<..N.....N....NN..NNNNNNNNNN.NN.NN.......N..NN.....NN.....NNNNNNNNNNNNNNNNN" );
	
	//m_Layouts.push_back( "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN" );
	//m_Layouts.push_back( "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN" );
	//m_Layouts.push_back( "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN" );
	//m_Layouts.push_back( "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN" );

	for ( int i = static_cast<int>(m_Layouts.size()); i < 16; ++i )
	{
		m_Layouts.push_back("NNNNNNN^NNNNNNNN.............NN.............NN.............N<.............>N.............NN.............NN.............NNNNNNNNvNNNNNNN");
	}
}

const std::vector<std::string>& RoomLayouts::GetLayouts() const
{
	return m_Layouts;
}