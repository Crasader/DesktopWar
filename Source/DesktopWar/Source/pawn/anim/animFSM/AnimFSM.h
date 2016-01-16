
#pragma once

#include <vector>


namespace Genius
{
	class AnimState;
	class ComPawnAnim;

	class AnimFSM
	{
	public:

		AnimFSM(ComPawnAnim* pComAnim);

		virtual ~AnimFSM();

		virtual void Initialize();

		virtual void Release();

		virtual void UpdateCurrentState();

		virtual void DoAction() = 0;

		virtual void SwitchToNextState();

	protected:

		std::vector<AnimState*>	m_animStateList;

		AnimState*			m_pCurrentState;

		AnimState*			m_pNextState;

		AnimState*			m_pDefaultState;

		ComPawnAnim*	m_pComPawnAnim;

	};

}

