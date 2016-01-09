#pragma once

#include "../EntityProcessingSystem.h"
#include "../ComponentMapper.h"
#include "../components/CommonCom.h"
#include "../components/BulletComponents.h"

namespace Genius
{
	class BulletDebugDrawSystem : public EntityProcessingSystem
	{
	private:
		ComponentMapper<BulletDebugDrawCom> debugDrawMapper;
		ComponentMapper<PositionCom> positionMapper;
		ComponentMapper<BulletTemplateCom>templateMapper;
		ComponentMapper<BoxColliderCom> boxColliderMapper;

	public:
		BulletDebugDrawSystem()
		{
			SetComponentTypes<BulletDebugDrawCom, PositionCom, BulletTemplateCom, BoxColliderCom>();
		}
		virtual const char* GetName(){ return "BulletDebugDrawSystem"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(IEventData const &event);

	};
};