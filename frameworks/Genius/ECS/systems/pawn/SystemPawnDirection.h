#ifndef _PAWN_DIRECTION_SYSTEM_H_
#define _PAWN_DIRECTION_SYSTEM_H_

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"
#include "../../components/common/ComPosition.h"
#include "../../components/pawn/ComPawnAgent.h"
#include "../../components/pawn/ComPawnDirection.h"


namespace Genius
{
	class SystemPawnDirection : public EntityProcessingSystem
	{
	private:
		ComponentMapper<ComPosition>				positionMapper;
		ComponentMapper<ComPawnAgent>		pawnAgentMapper;
		ComponentMapper<ComPawnDirection>	pawnDirectionMapper;

	public:
		SystemPawnDirection()
		{
			SetComponentTypes<ComPosition, ComPawnAgent, ComPawnDirection>();
		}
		virtual const char* GetName(){ return "SystemPawnDirection"; }
		virtual void Initialize();

		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(IEventData const &event);

	private:
		unsigned int CalculateDirection(ComPawnDirection* pawnDir, float x, float y);
		void ChangeDirection(ComPawnDirection* dirCom, unsigned int dir);
	};
};

#endif