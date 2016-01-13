#pragma once

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"
#include "../../components/common/ComPosition.h"
#include "../../components/common/ComBoxCollider.h"
#include "../../components/pawn/ComPawnDebugDraw.h"
#include "../../components/pawn/ComPawnTemplate.h"


namespace Genius
{
	class SystemPawnDebugDraw : public EntityProcessingSystem
	{
	private:
		ComponentMapper<ComPawnDebugDraw> debugDrawMapper;
		ComponentMapper<ComPosition> positionMapper;
		ComponentMapper<ComPawnTemplate>pawnTemplateMapper;
		ComponentMapper<ComBoxCollider> boxColliderMapper;

	public:
		SystemPawnDebugDraw()
		{
			SetComponentTypes<ComPawnDebugDraw, ComPosition, ComPawnTemplate, ComBoxCollider>();
		}
		virtual const char* GetName(){ return "SystemPawnDebugDraw"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(IEventData const &event);

	};
};