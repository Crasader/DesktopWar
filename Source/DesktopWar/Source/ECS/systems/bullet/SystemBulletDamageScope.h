#pragma once

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"
#include "../../components/common/ComPosition.h"
#include "../../components/bullet/ComBulletDamageScope.h"
#include "../../components/bullet/ComBulletTemplate.h"

namespace Genius
{
	class SystemBulletDamageScope : public EntityProcessingSystem
	{
	private:
		ComponentMapper<ComPosition> positionMapper;
		ComponentMapper<ComBulletDamageScope> damageMapper;
		ComponentMapper<ComBulletTemplate> bulletTemplateMapper;

	public:
		SystemBulletDamageScope()
		{
			SetComponentTypes<ComPosition, ComBulletDamageScope, ComBulletTemplate>();
		}
		virtual const char* GetName(){ return "SystemBulletDamageScope"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(IEventData const &event);
		void OnCollision(int id1, int id2);

	private:
		bool TriggerBulletBuff(IEventData const &evnt);
		void FindTargetsInScope(Entity* pEntity, int radius, bool sameTeam, std::vector<Entity*>& eneityIDList);
	};
};