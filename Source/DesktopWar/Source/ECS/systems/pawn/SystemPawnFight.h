#ifndef _PAWN_FIND_ENEMY_SYSTEM_H_
#define _PAWN_FIND_ENEMY_SYSTEM_H_

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"
#include "../../components/common/ComPosition.h"
#include "../../components/common/ComBoxCollider.h"
#include "../../components/pawn/ComPawnFight.h"
#include "../../components/pawn/ComPawnAnim.h"
#include "../../components/pawn/ComPawnAttribute.h"
#include "../../components/pawn/ComPawnAgent.h"

namespace Genius
{
	class SystemPawnFight : public EntityProcessingSystem
	{
	private:
		ComponentMapper<ComPosition>					positionMapper;
		ComponentMapper<ComBoxCollider>				colliderMapper;
		ComponentMapper<ComPawnFight>				pawnFightMapper;
		ComponentMapper<ComPawnAgent>		pawnAgentMapper;
		ComponentMapper<ComPawnAttribute>		pawnAttributeMapper;
		ComponentMapper<ComPawnAnim>				pawnAnimMapper;

	public:
		SystemPawnFight()
		{
			SetComponentTypes<ComPawnFight, ComPosition, ComBoxCollider, ComPawnAgent, ComPawnAttribute, ComPawnAnim>();
		}
		virtual const char* GetName(){ return "SystemPawnFight"; }
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