
#pragma once

#include <vector>

namespace Genius
{
	class AnimState;


	class AnimFSM
	{
	public:

		AnimFSM();

		virtual ~AnimFSM();

		virtual void Initialize();

		virtual void UpdateCurrentState();

		virtual void DoAction() = 0;

		virtual void SwitchToNextState();

	protected:

		std::vector<AnimState*>	m_stateList;

		AnimState*			m_pCurrentState;

		AnimState*			m_pNextState;

		AnimState*			m_pDefaultState;

	};

}

