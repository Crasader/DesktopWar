#pragma once

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"
#include "../../components/common/ComPosition.h"
#include "../../components/common/ComVelocity.h"
#include "../../components/bullet/ComBulletAnimBomb.h"

namespace Genius
{
	class SystemBulletBombAnim : public EntityProcessingSystem
	{
	private:
		ComponentMapper<ComPosition> positionMapper;
		ComponentMapper<ComVelocity> velocityMapper;
		ComponentMapper<ComBulletAnimBomb> animMapper;

	public:
		SystemBulletBombAnim()
		{
			SetComponentTypes<ComPosition, ComVelocity, ComBulletAnimBomb>();
		}
		virtual const char* GetName(){ return "SystemBulletBombAnim"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(IEventData const &event);

	private:
		void OnBulletHit(IEventData const &evnt);
		void OnReachDest(IEventData const &evnt);
	};
};