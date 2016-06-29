
#pragma once

namespace Genius
{
	class PawnAction;

	class ActionHandler
	{
	public:
		virtual ~ActionHandler(){}
		virtual void HandleAction(PawnAction* pAction) = 0;

	};
}