#pragma once

#include "../core/EntityProcessingSystem.h"
#include "../core/ComponentMapper.h"
#include "../components/CommonCom.h"
#include "../components/BulletComponents.h"

namespace Genius
{
	class BulletDamageScopeSystem : public EntityProcessingSystem
	{
	private:
		ComponentMapper<PositionCom> positionMapper;
		ComponentMapper<BulletDamageScopeCom> damageMapper;
		ComponentMapper<BulletTemplateCom> bulletTemplateMapper;

	public:
		BulletDamageScopeSystem()
		{
			SetComponentTypes<PositionCom, BulletDamageScopeCom, BulletTemplateCom>();
		}
		virtual const char* GetName(){ return "BulletDamageScopeSystem"; }
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