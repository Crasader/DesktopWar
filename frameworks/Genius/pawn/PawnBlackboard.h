
#pragma once
#include <queue>
#include <list>

namespace Genius
{
	class ComPawnAgent;
	class PawnAction;
	class ActionHandler;

	class PawnBlackboard
	{
	public:
		PawnBlackboard(ComPawnAgent* agent);

		~PawnBlackboard();

		void Update();

		void AddAction(PawnAction* pAction);

		void FinishAction(PawnAction* pAction);

		void AddActionHandler(ActionHandler* pHandler);

		void RemoveActionHandler(ActionHandler* pHandler);

	public:
		ComPawnAgent*	m_pAgent;

		int		m_currentHP;

		std::queue<PawnAction*>		m_actionQueue;

		std::list<ActionHandler*>			m_actionHandlers;
	};

}