#pragma once

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"
#include "../../components/common/PositionCom.h"
#include "../../components/common/TargetCom.h"
#include "../../components/bullet/BulletTemplateCom.h"

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