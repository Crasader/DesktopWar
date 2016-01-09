#pragma once

#include "../EntityProcessingSystem.h"
#include "../ComponentMapper.h"
#include "../components/CommonCom.h"
#include "../components/CommonCom.h"

namespace Genius
{
	class BoxColliderSystem : public EntityProcessingSystem
	{
	private:
		ComponentMapper<PositionCom> positionMapper;
		ComponentMapper<BoxColliderCom> colliderMapper;
		ComponentMapper<ColliderHandlerCom> handlerMapper;

	public:
		BoxColliderSystem()
		{
			SetComponentTypes<PositionCom, BoxColliderCom, ColliderHandlerCom>();
		}
		virtual const char* GetName(){ return "BoxColliderSystem"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(IEventData const &event);

	private:
		bool IsCollidedBetween(PositionCom* posCom, BoxColliderCom* colliderCom, PositionCom* otherPosCom, BoxColliderCom* otherColliderCom);
		bool IsAlreadyCollided(BoxColliderCom* colliderCom, Entity* entity2);
	};
};