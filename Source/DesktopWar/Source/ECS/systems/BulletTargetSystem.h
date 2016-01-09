#pragma once

#include "../EntityProcessingSystem.h"
#include "../ComponentMapper.h"
#include "../components/CommonCom.h"
#include "../components/BulletComponents.h"

namespace Genius
{
	class BulletTargetSystem : public EntityProcessingSystem
	{
	private:
		ComponentMapper<PositionCom> positionMapper;
		ComponentMapper<TargetCom> targetMapper;
		ComponentMapper<BulletTemplateCom> templateMapper;

	public:
		BulletTargetSystem()
		{
			SetComponentTypes<PositionCom, TargetCom, BulletTemplateCom>();
		}
		virtual const char* GetName(){ return "BulletTargetSystem"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(IEventData const &event);
	};
};