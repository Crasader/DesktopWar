#pragma once

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"
#include "../../components/common/PositionCom.h"
#include "../../components/bullet/BulletDamageNoneCom.h"
#include "../../components/bullet/BulletTemplateCom.h"

namespace Genius
{
	class BulletDamageNoneSystem : public EntityProcessingSystem
	{
	private:
		ComponentMapper<PositionCom> positionMapper;
		ComponentMapper<BulletDamageNoneCom> damageMapper;
		ComponentMapper<BulletTemplateCom> bulletTemplateMapper;

	public:
		BulletDamageNoneSystem()
		{
			SetComponentTypes<PositionCom, BulletDamageNoneCom, BulletTemplateCom>();
		}
		virtual const char* GetName(){ return "BulletDamageNoneSystem"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(IEventData const &event);

	private:
		bool TriggerBulletBuff(IEventData const &evnt);
	};
};