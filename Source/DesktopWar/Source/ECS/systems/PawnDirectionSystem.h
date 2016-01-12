#ifndef _PAWN_DIRECTION_SYSTEM_H_
#define _PAWN_DIRECTION_SYSTEM_H_

#include "../core/EntityProcessingSystem.h"
#include "../core/ComponentMapper.h"
#include "../components/common/PositionCom.h"
#include "../components/pawn/PawnDirectionCom.h"


namespace Genius
{
	class PawnDirectionSystem : public EntityProcessingSystem
	{
	private:
		ComponentMapper<PawnDirectionCom>	pawnDirectionMapper;
		ComponentMapper<PositionCom>				positionMapper;

	public:
		PawnDirectionSystem()
		{
			SetComponentTypes<PawnDirectionCom, PositionCom>();
		}
		virtual const char* GetName(){ return "PawnDirectionSystem"; }
		virtual void Initialize();

		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(IEventData const &event);

	private:
		unsigned int CalculateDirection(PawnDirectionCom* pawnDir, float x, float y);
		void ChangeDirection(PawnDirectionCom* dirCom, unsigned int dir);
	};
};

#endif