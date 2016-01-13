#pragma once

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"
#include "../../components/common/ComPosition.h"
#include "../../components/common/ComBoxCollider.h"
#include "../../components/bullet/ComBulletDebugDraw.h"
#include "../../components/bullet/ComBulletTemplate.h"

namespace Genius
{
	class SystemBulletDebugDraw : public EntityProcessingSystem
	{
	private:
		ComponentMapper<ComBulletDebugDraw> debugDrawMapper;
		ComponentMapper<ComPosition> positionMapper;
		ComponentMapper<ComBulletTemplate>templateMapper;
		ComponentMapper<ComBoxCollider> boxColliderMapper;

	public:
		SystemBulletDebugDraw()
		{
			SetComponentTypes<ComBulletDebugDraw, ComPosition, ComBulletTemplate, ComBoxCollider>();
		}
		virtual const char* GetName(){ return "SystemBulletDebugDraw"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(IEventData const &event);

	};
};