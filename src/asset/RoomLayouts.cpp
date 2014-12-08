#include "RoomLayouts.h"

/*
N.............N N.............N NNNNNNNNNNNNNNN NNNNNNNNNNNNNNN
N.............N N.............N N.............N N.-...........N
N.............N N.............N N..........NN.N N.-.NNNNNNNNN.N
N.............N N.............N N...-.......N.N NNN...N....N..N
N.............> <.............> <...N...N...N.> <.NNN.N.N.NN.NN
NNNNNNNNNNNNNNN NNN.........NNN N...N...N...N.N N.N..|N.N|.N..N
NNNNNNNNNNNNNNN NNNN.......NNNN NN............N N.NNN.N.N.NNN.N
NNNNNNNNNNNNNNN NNNNN.....NNNNN NNN...........N N.....N.N.....N
NNNNNNNNNNNNNNN NNNNNNNNNNNNNNN NNNNNNNNNNNNNNN NNNNNNNvNNNNNNN

NNNNNNNNNNNNNNN NNNNNNNNNNNNNNN NNNNNNNNNNNNNNN NNNNNNN^NNNNNNN
NNN..|||||..NNN N...-.....-...N N......-......N NN......NNNNNNN
NNN....-....NNN N.N.N.N.N.N.N.N NNNN...N...NNNN NN.|NNN..NNNNNN
NNN..NNNNNN...N N..|...|...|..N N....|.N.|....N NN.NNNN...NNNNN
NNN..|||||.NN.> <.N.-.....-.N.> <.N...jNj.....> <..NNNN.......N
NNN....-....NNN N|N.N|N.N|N.N.N N.N..NNNNN..NNN NNNNNNN.NNNN..N
NNNNNNNNNNN...N N.............N N.....N.......N NNNNNNN.NNNNN.N
NNN....-....N.N N............jN N.-.j.N.N.j.-.N NNNNNNN.......N
NNNNNNNvNNNNNNN NNNNNNNNNNNNNNN NNNNNNNvNNNNNNN NNNNNNNvNNNNNNN

NNNNNNN^NNNNNNN NNNNNNNNNNNNNNN NNNNNNN^NNNNNNN NNNNNNN^NNNNNNN
NNNNN.....NNNNN N.............N N.....N.......N N.......NNNNNNN
NNNNN|NN-.NNNNN N.............N N.....NjN.....N N.-.NNNNNNNNNNN
NNNN........NNN N.............N N.....NNNNNNN.N NNN..N...-...NN
NNNN|NN-.NN|NNN N.....13......> <...........N.> <..N..-..N.||.N
NNNN........NNN N.............N N...........NNN N..NNNNNNNNNN.N
NNNNN|NN-.NNNNN N.............N N.............N N|NN.|.-...N..N
NNNNN...j.NNNNN N.............N N.............N N.....NN..-..NN
NNNNNNNvNNNNNNN NNNNNNNvNNNNNNN NNNNNNNvNNNNNNN NNNNNNNNNNNNNNN

NNNNNNN^NNNNNNN NNNNNNN^NNNNNNN NNNNNNN^NNNNNNN NNNNNNNNNNNNNNN
N...|...|...N.N N.............N N.............N N.............N
NN.N-N-N-N-NN.N N.............N N.............N N.............N
N.....|...|.N.N N.............N N.............N N.............N
NN-N-N-N-N.NN.> <.....12......N N.....15......> <.....16......N
N...|...|...N.N N.............N N.............N N.............N
NN.N-N-N-N-NN.N N.............N N.............N N.............N
N.|...|...|..jN N.............N N.............N N.............N
NNNNNNNNNNNNNNN NNNNNNNNNNNNNNN NNNNNNNNNNNNNNN NNNNNNNNNNNNNNN
*/

RoomLayouts::RoomLayouts()
{
	m_Layouts.push_back( "N.............NN.............NN.............NN.............NN.............>NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN" );
	m_Layouts.push_back( "N.............NN.............NN.............NN.............N<.............>NNN.........NNNNNNN.......NNNNNNNNN.....NNNNNNNNNNNNNNNNNNNN" );
	m_Layouts.push_back( "NNNNNNNNNNNNNNNN.............NN..........NN.NN...-.......N.N<...N...N...N.>N...N...N...N.NNN............NNNN...........NNNNNNNNNNNNNNNN" );
	m_Layouts.push_back( "NNNNNNNNNNNNNNNN.-...........NN.-.NNNNNNNNN.NNNN...N....N..N<.NNN.N.N.NN.NNN.N..|N.N|.N..NN.NNN.N.N.NNN.NN.....N.N.....NNNNNNNNvNNNNNNN" );
	
	m_Layouts.push_back( "NNNNNNNNNNNNNNNNNN..|||||..NNNNNN....-....NNNNNN..NNNNNN...NNNN..|||||.NN.>NNN....-....NNNNNNNNNNNNNN...NNNN....-....N.NNNNNNNNvNNNNNNN" );
	m_Layouts.push_back( "NNNNNNNNNNNNNNNN...-.....-...NN.N.N.N.N.N.N.NN..|...|...|..N<.N.-.....-.N.>N|N.N|N.N|N.N.NN.............NN............jNNNNNNNNNNNNNNNN" );
	m_Layouts.push_back( "NNNNNNNNNNNNNNNN......-......NNNNN...N...NNNNN....|.N.|....N<.N...jNj.....>N.N..NNNNN..NNNN.....N.......NN.-.j.N.N.j.-.NNNNNNNNvNNNNNNN" );
	m_Layouts.push_back( "NNNNNNN^NNNNNNNNN......NNNNNNNNN.|NNN..NNNNNNNN.NNNN...NNNNN<..NNNN.......NNNNNNNN.NNNN..NNNNNNNN.NNNNN.NNNNNNNN.......NNNNNNNNvNNNNNNN" );
	
	m_Layouts.push_back( "NNNNNNN^NNNNNNNNNNNN.....NNNNNNNNNN|NN-.NNNNNNNNN........NNNNNNN|NN-.NN|NNNNNNN........NNNNNNNN|NN-.NNNNNNNNNN...j.NNNNNNNNNNNNvNNNNNNN" );
	m_Layouts.push_back( "NNNNNNNNNNNNNNNN.............NN.............NN.............NN.....13......>N.............NN.............NN.............NNNNNNNNvNNNNNNN" );
	m_Layouts.push_back( "NNNNNNN^NNNNNNNN.....N.......NN.....NjN.....NN.....NNNNNNN.N<...........N.>N...........NNNN.............NN.............NNNNNNNNvNNNNNNN" );
	m_Layouts.push_back( "NNNNNNN^NNNNNNNN.......NNNNNNNN.-.NNNNNNNNNNNNNN..N...-...NN<..N..-..N.||.NN..NNNNNNNNNN.NN|NN.|.-...N..NN.....NN..-..NNNNNNNNNNNNNNNNN" );
	
	m_Layouts.push_back( "NNNNNNN^NNNNNNNN...|...|...N.NNN.N-N-N-N-NN.NN.....|...|.N.NNN-N-N-N-N.NN.>N...|...|...N.NNN.N-N-N-N-NN.NN.|...|...|..jNNNNNNNNNNNNNNNN" );
	m_Layouts.push_back( "NNNNNNN^NNNNNNNN.............NN.............NN.............N<.....12......NN.............NN.............NN.............NNNNNNNNNNNNNNNN" );
	m_Layouts.push_back( "NNNNNNN^NNNNNNNN.............NN.............NN.............NN.....15......>N.............NN.............NN.............NNNNNNNNNNNNNNNN" );
	m_Layouts.push_back( "NNNNNNNNNNNNNNNN.............NN.............NN.............N<.....16......NN.............NN.............NN.............NNNNNNNNNNNNNNNN" );

	for ( int i = static_cast<int>(m_Layouts.size()); i < 16; ++i )
	{
		m_Layouts.push_back("NNNNNNN^NNNNNNNN.............NN.............NN.............N<.............>N.............NN.............NN.............NNNNNNNNvNNNNNNN");
	}
}

const std::vector<std::string>& RoomLayouts::GetLayouts() const
{
	return m_Layouts;
}