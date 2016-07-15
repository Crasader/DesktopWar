#pragma once

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"
#include "../../components/common/ComTransform.h"
#include "../../components/common/ComBoxCollider.h"
#include "../../components/pawn/ComPawnDebugDraw.h"
#include "../../components/pawn/ComPawnAgent.h"


namespace Genius
{
	class SystemPawnDebugDraw : public EntityProcessingSystem
	{
	private:
		ComponentMapper<ComPawnDebugDraw> debugDrawMapper;
		ComponentMapper<ComTransform> transMapper;
		ComponentMapper<ComPawnAgent>pawnAgentMapper;
		ComponentMapper<ComBoxCollider> boxColliderMapper;

	public:
		SystemPawnDebugDraw()
		{
			SetComponentTypes<ComPawnDebugDraw, ComTransform, ComPawnAgent, ComBoxCollider>();
		}
		virtual const char* GetName(){ return "SystemPawnDebugDraw"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(IEventData const &event);

	};
};