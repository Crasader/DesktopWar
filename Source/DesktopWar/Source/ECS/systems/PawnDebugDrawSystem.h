#pragma once

#include "../EntityProcessingSystem.h"
#include "../ComponentMapper.h"
#include "../components/CommonCom.h"
#include "../components/PawnComponents.h"

namespace Genius
{
	class PawnDebugDrawSystem : public EntityProcessingSystem
	{
	private:
		ComponentMapper<PawnDebugDrawCom> debugDrawMapper;
		ComponentMapper<PositionCom> positionMapper;
		ComponentMapper<PawnTemplateCom>pawnTemplateMapper;
		ComponentMapper<BoxColliderCom> boxColliderMapper;

	public:
		PawnDebugDrawSystem()
		{
			SetComponentTypes<PawnDebugDrawCom, PositionCom, PawnTemplateCom, BoxColliderCom>();
		}
		virtual const char* GetName(){ return "PawnDebugDrawSystem"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(IEventData const &event);

	};
};