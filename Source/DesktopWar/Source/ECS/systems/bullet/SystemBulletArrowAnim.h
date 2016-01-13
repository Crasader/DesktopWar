#pragma once

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"
#include "../../components/common/ComPosition.h"
#include "../../components/common/ComVelocity.h"
#include "../../components/bullet/ComBulletAnimArrow.h"

namespace Genius
{
	class SystemBulletArrowAnim : public EntityProcessingSystem
	{
	private:
		ComponentMapper<ComPosition> positionMapper;
		ComponentMapper<ComVelocity> velocityMapper;
		ComponentMapper<ComBulletAnimArrow> animMapper;

	public:
		SystemBulletArrowAnim()
		{
			SetComponentTypes<ComPosition, ComVelocity, ComBulletAnimArrow>();
		}
		virtual const char* GetName(){ return "SystemBulletArrowAnim"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(IEventData const &evnt);

	private:
		void OnBulletHit(IEventData const &evnt);
		void OnReachDest(IEventData const &evnt);
	};
};