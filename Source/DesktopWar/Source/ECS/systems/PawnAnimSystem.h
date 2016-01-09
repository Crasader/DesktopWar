#ifndef _PAWN_ANIM_SYSTEM_H_
#define _PAWN_ANIM_SYSTEM_H_

#include "../EntityProcessingSystem.h"
#include "../ComponentMapper.h"
#include "../components/PawnComponents.h"
#include "../components/CommonCom.h"
#include "../../common/2Ddef.h"
#include "../../pawn/PawnDefines.h"

namespace Genius
{
	class PawnAnimSystem : public EntityProcessingSystem
	{
	private:
		ComponentMapper<PawnAnimCom>	pawnAnimMapper;
		ComponentMapper<PositionCom>		positionMapper;
		ComponentMapper<PawnDirectionCom>	pawnDirectionMapper;

	public:
		PawnAnimSystem()
		{
			SetComponentTypes<PawnAnimCom, PositionCom, PawnDirectionCom>();
		}
		virtual const char* GetName(){ return "PawnAnimSystem"; }
		virtual void Initialize();

		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(IEventData const &event);

	private:
		void PlayAnimation(PawnAnimCom* animCom, PawnDirectionCom* dirCom, ActionType act);

		void PlayIdle(PawnAnimCom* animCom, PawnDirectionCom* dirCom);
		void PlayDie(PawnAnimCom* animCom, PawnDirectionCom* dirCom);
		void PlayMove(PawnAnimCom* animCom, PawnDirectionCom* dirCom);
		void PlayAtkNear(PawnAnimCom* animCom, PawnDirectionCom* dirCom);
		void PlayAtkNear2(PawnAnimCom* animCom, PawnDirectionCom* dirCom);
		void PlayAtkFar(PawnAnimCom* animCom, PawnDirectionCom* dirCom);
		void PlaySkill1(PawnAnimCom* animCom, PawnDirectionCom* dirCom);
		void PlaySkill2(PawnAnimCom* animCom, PawnDirectionCom* dirCom);
		void PlaySkill3(PawnAnimCom* animCom, PawnDirectionCom* dirCom);
	};
};

#endif