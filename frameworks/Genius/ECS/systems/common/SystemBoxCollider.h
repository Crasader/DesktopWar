#pragma once

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"
#include "../../components/common/ComTransform.h"
#include "../../components/common/ComBoxCollider.h"
#include "../../components/common/ComColliderHandler.h"
namespace Genius
{
	class SystemBoxCollider : public EntityProcessingSystem
	{
	private:
		ComponentMapper<ComTransform> positionMapper;
		ComponentMapper<ComBoxCollider> colliderMapper;
		ComponentMapper<ComColliderHandler> handlerMapper;

	public:
		SystemBoxCollider()
		{
			SetComponentTypes<ComTransform, ComBoxCollider, ComColliderHandler>();
		}
		virtual const char* GetName(){ return "SystemBoxCollider"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(IEventData const &event);

	private:
		bool IsCollidedBetween(ComTransform* posCom, ComBoxCollider* colliderCom, ComTransform* otherPosCom, ComBoxCollider* otherColliderCom);
		bool IsAlreadyCollided(ComBoxCollider* colliderCom, Entity* entity2);
	};
};