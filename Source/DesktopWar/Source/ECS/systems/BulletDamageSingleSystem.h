#pragma once

#include "../core/EntityProcessingSystem.h"
#include "../core/ComponentMapper.h"
#include "../components/CommonCom.h"
#include "../components/BulletComponents.h"

namespace Genius
{
	class BulletDamageSingleSystem : public EntityProcessingSystem
	{
	private:
		ComponentMapper<PositionCom> positionMapper;
		ComponentMapper<BulletDamageSingleCom> damageMapper;
		ComponentMapper<BulletTemplateCom> bulletTemplateMapper;

	public:
		BulletDamageSingleSystem()
		{
			SetComponentTypes<PositionCom, BulletDamageSingleCom, BulletTemplateCom>();
		}
		virtual const char* GetName(){ return "BulletDamageSingleSystem"; }
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