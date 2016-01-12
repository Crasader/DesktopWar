#pragma once

#include "../core/EntityProcessingSystem.h"
#include "../core/ComponentMapper.h"
#include "../components/common/PositionCom.h"
#include "../components/common/BoxColliderCom.h"
#include "../components/common/ColliderHandlerCom.h"
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