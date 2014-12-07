#include "RoomLayouts.h"

/*	
NNNNNNNNNNNNNNN NNNNNNN^NNNNNNN NNNNNNN^NNNNNNN NNNNNNN^NNNNNNN
N.............N N.............N N.............N N.............N
N.............N N.............N N.............N N.............N
N.............N N.............N N.............N N.............N
N.............> <.............> <.............> <.............>
NNNNNNNNNNNNNNN N.............N N.............N N.............N
NNNNNNNNNNNNNNN N.............N N.............N N.............N
NNNNNNNNNNNNNNN N.............N N.............N N.............N
NNNNNNNNNNNNNNN NNNNNNNvNNNNNNN NNNNNNNvNNNNNNN NNNNNNNvNNNNNNN

NNNNNNN^NNNNNNN NNNNNNN^NNNNNNN NNNNNNN^NNNNNNN NNNNNNN^NNNNNNN
N.............N N.............N N.............N N.............N
N.............N N.............N N.............N N.............N
N.............N N.............N N.............N N.............N
<.............> <.............> <.............> <.............>
N.............N N.............N N.............N N.............N
N.............N N.............N N.............N N.............N
N.............N N.............N N.............N N.............N
NNNNNNNvNNNNNNN NNNNNNNvNNNNNNN NNNNNNNvNNNNNNN NNNNNNNvNNNNNNN

NNNNNNN^NNNNNNN NNNNNNN^NNNNNNN NNNNNNN^NNNNNNN NNNNNNN^NNNNNNN
N.............N N.............N N.............N N.............N
N.............N N.............N N.............N N.............N
N.............N N.............N N.............N N.............N
<.............> <.............> <.............> <.............>
N.............N N.............N N.............N N.............N
N.............N N.............N N.............N N.............N
N.............N N.............N N.............N N.............N
NNNNNNNvNNNNNNN NNNNNNNvNNNNNNN NNNNNNNvNNNNNNN NNNNNNNvNNNNNNN

NNNNNNN^NNNNNNN NNNNNNN^NNNNNNN NNNNNNN^NNNNNNN NNNNNNN^NNNNNNN
N.............N N.............N N.............N N.............N
N.............N N.............N N.............N N.............N
N.............N N.............N N.............N N.............N
<.............> <.............> <.............> <.............>
N.............N N.............N N.............N N.............N
N.............N N.............N N.............N N.............N
N.............N N.............N N.............N N.............N
NNNNNNNvNNNNNNN NNNNNNNvNNNNNNN NNNNNNNvNNNNNNN NNNNNNNvNNNNNNN
*/

RoomLayouts::RoomLayouts()
{
	m_Layouts.push_back( "NNNNNNNNNNNNNNNN.............NN.............NN.............NN.............>NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN" );

	for ( int i = static_cast<int>(m_Layouts.size()); i < 16; ++i )
	{
		m_Layouts.push_back("NNNNNNN^NNNNNNNN.............NN.............NN.............N<.............>N.............NN.............NN.............NNNNNNNNvNNNNNNN");
	}
}

const std::vector<std::string>& RoomLayouts::GetLayouts() const
{
	return m_Layouts;
}