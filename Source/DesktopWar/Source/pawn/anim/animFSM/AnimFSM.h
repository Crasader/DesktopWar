
#pragma once

#include <map>


namespace Genius
{
	class AnimState;
	class ComPawnAnim;
	class PawnAction;

	class AnimFSM
	{
	public:

		AnimFSM(ComPawnAnim* pComAnim);

		virtual ~AnimFSM();

		virtual void Initialize();

		virtual void Release();

		virtual void UpdateCurrentState();

		virtual void DoAction(PawnAction* pAction) = 0;

		virtual void SwitchToNextState(PawnAction* pAction);

	protected:

		std::map<int, AnimState*>	m_animStateList;

		AnimState*			m_pCurrentState;

		AnimState*			m_pNextState;

		AnimState*			m_pDefaultState;

		ComPawnAnim*	m_pComPawnAnim;

	};

}

