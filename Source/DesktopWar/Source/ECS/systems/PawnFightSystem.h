#ifndef _PAWN_FIND_ENEMY_SYSTEM_H_
#define _PAWN_FIND_ENEMY_SYSTEM_H_

#include "../core/EntityProcessingSystem.h"
#include "../core/ComponentMapper.h"
#include "../components/PawnComponents.h"
#include "../components/common/PositionCom.h"
#include "../components/common/BoxColliderCom.h"

namespace Genius
{
	class PawnFightSystem : public EntityProcessingSystem
	{
	private:
		ComponentMapper<PositionCom>					positionMapper;
		ComponentMapper<BoxColliderCom>				colliderMapper;
		ComponentMapper<PawnFightCom>				pawnFightMapper;
		ComponentMapper<PawnTemplateCom>		pawnTemplateMapper;
		ComponentMapper<PawnAttributeCom>		pawnAttributeMapper;
		ComponentMapper<PawnAnimCom>				pawnAnimMapper;

	public:
		PawnFightSystem()
		{
			SetComponentTypes<PawnFightCom, PositionCom, BoxColliderCom, PawnTemplateCom, PawnAttributeCom, PawnAnimCom>();
		}
		virtual const char* GetName(){ return "PawnFightSystem"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* e);
		virtual bool HandleEvent(IEventData const &evt);

	public:
		int FindNearestTarget(Entity* e, bool sameTeam, bool includeSelf);
		void FindTargetsInScope(int entityID, int scopeSize, bool sameTeam, bool includeSelf, std::vector<Entity*>& eneityIDList);
		int FindFirstTargetByTeam(int team);

	private:
		void UpdateLifeBar(Entity* e);
		bool IsOldTargetVaild(Entity* e);
		void HandleAttackTarget(IEventData const &evt);
		void HandleAttackTarget2(IEventData const &evt);
		void HandleUseSkill(IEventData const &evt);
		void HandleHurt(IEventData const &evt);
	};
};

#endif