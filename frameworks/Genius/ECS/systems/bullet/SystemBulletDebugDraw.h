#pragma once

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"
#include "../../components/common/ComTransform.h"
#include "../../components/common/ComBoxCollider.h"
#include "../../components/bullet/ComBulletDebugDraw.h"
#include "../../components/pawn/ComPawnAgent.h"

namespace Genius
{
	class SystemBulletDebugDraw : public EntityProcessingSystem
	{
	private:
		ComponentMapper<ComBulletDebugDraw> debugDrawMapper;
		ComponentMapper<ComTransform> transMapper;
		ComponentMapper<ComBoxCollider> boxColliderMapper;
		ComponentMapper<ComPawnAgent> agentMapper;

	public:
		SystemBulletDebugDraw()
		{
			SetComponentTypes<ComBulletDebugDraw, ComTransform, ComBoxCollider, ComPawnAgent>();
		}
		virtual const char* GetName(){ return "SystemBulletDebugDraw"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(IEventData const &event);

	};
};