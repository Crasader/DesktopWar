#pragma once

#include <unordered_map>

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"
#include "../../components/common/ComTransform.h"
#include "../../components/common/ComBoxCollider.h"


namespace Genius
{
	class SystemBoxCollider : public EntityProcessingSystem
	{
	private:
		ComponentMapper<ComTransform> transMapper;
		ComponentMapper<ComBoxCollider> colliderMapper;

	public:
		SystemBoxCollider()
		{
			SetComponentTypes<ComTransform, ComBoxCollider>();
		}
		virtual const char* GetName(){ return "SystemBoxCollider"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(IEventData const &event);

	private:
		bool IsCollidedBetween(ComTransform* posCom, ComBoxCollider* colliderCom, ComTransform* otherPosCom, ComBoxCollider* otherColliderCom);

	private:
		std::unordered_map<int, std::list<int>> m_colliderData;
	};
};