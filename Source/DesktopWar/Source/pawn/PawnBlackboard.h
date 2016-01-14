
#pragma once

namespace Genius
{
	class ComPawnAgent;

	class PawnBlackboard
	{
	public:
		PawnBlackboard(ComPawnAgent* agent);
		~PawnBlackboard();


	public:
		ComPawnAgent*	m_pAgent;
		int		m_currentHP;
	};

}