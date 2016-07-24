
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
		void SetTargetType(int tp);
		void SetTargetID(int id);
		void SetTargetX(float x);
		void SetTargetY(float y);

	public:
		ComPawnAgent*	m_pAgent;

		// target stuff
		int		targetType;
		int		targetID;
		float		targetX;
		float		targetY;

		std::queue<PawnAction*>		m_actionQueue;

		std::list<ActionHandler*>			m_actionHandlers;

	private:
		int		m_attr[10];

	};

}