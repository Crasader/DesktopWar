#pragma once

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"
#include "../../components/common/ComPosition.h"
#include "../../components/bullet/ComBulletDamageSingle.h"
#include "../../components/bullet/ComBulletTemplate.h"

namespace Genius
{
	class SystemBulletDamageSingle : public EntityProcessingSystem
	{
	private:
		ComponentMapper<ComPosition> positionMapper;
		ComponentMapper<ComBulletDamageSingle> damageMapper;
		ComponentMapper<ComBulletTemplate> bulletTemplateMapper;

	public:
		SystemBulletDamageSingle()
		{
			SetComponentTypes<ComPosition, ComBulletDamageSingle, ComBulletTemplate>();
		}
		virtual const char* GetName(){ return "SystemBulletDamageSingle"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(IEventData const &event);
		void collisionHandler(int id1, int id2);

	private:
		bool TriggerBulletBuff(IEventData const &evnt);
		void FindTargetsInScope(Entity* pEntity, int radius, bool sameTeam, std::vector<Entity*>& eneityIDList);
	};
};