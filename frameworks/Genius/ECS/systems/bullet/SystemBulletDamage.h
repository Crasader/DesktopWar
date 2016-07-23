#pragma once

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"
#include "../../components/common/ComTransform.h"
#include "../../components/bullet/ComBulletDamage.h"
#include "../../components/pawn/ComPawnAgent.h"

namespace Genius
{
	class SystemBulletDamage : public EntityProcessingSystem
	{
	private:
		ComponentMapper<ComTransform> transMapper;
		ComponentMapper<ComBulletDamage> damageMapper;
		ComponentMapper<ComPawnAgent> agentMapper;

	public:
		SystemBulletDamage()
		{
			SetComponentTypes<ComTransform, ComBulletDamage, ComPawnAgent>();
		}
		virtual const char* GetName(){ return "SystemBulletDamageSingle"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(const IEventData &evt);
		void collisionHandler(const IEventData &evt);

	private:
		bool TriggerBulletBuff(IEventData const &evnt);
		void FindTargetsInScope(Entity* pEntity, int radius, bool sameTeam, std::vector<Entity*>& eneityIDList);
	};
};