#pragma once

#include "../core/EntityProcessingSystem.h"
#include "../core/ComponentMapper.h"
#include "../components/common/PositionCom.h"
#include "../components/common/BoxColliderCom.h"
#include "../components/pawn/PawnDebugDrawCom.h"
#include "../components/pawn/PawnTemplateCom.h"


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