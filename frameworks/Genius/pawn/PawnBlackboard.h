
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

		int GetAttr(int type);
		void SetAttr(int type, int value);
		void ModAttr(int type, int value);

	public:
		ComPawnAgent*	m_pAgent;

		int team;
		/*int		m_HP;
		int		m_moveSpeed;
		int		m_attackSpeed;
		int		m_attack;
		int		m_defencePhy;
		int		m_defenceMag;*/

		std::queue<PawnAction*>		m_actionQueue;

		std::list<ActionHandler*>			m_actionHandlers;

	private:
		int		m_attr[10];

	};

}