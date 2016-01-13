#ifndef _MOVEMENT_SYSTEM_H_
#define _MOVEMENT_SYSTEM_H_

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"
#include "../../components/common/PositionCom.h"
#include "../../components/common/VelocityCom.h"

namespace Genius
{
	class MovementSystem : public EntityProcessingSystem
	{
	private:
		ComponentMapper<VelocityCom> velocityMapper;
		ComponentMapper<PositionCom> positionMapper;

	public:
		MovementSystem()
		{
			SetComponentTypes<VelocityCom, PositionCom>();
		}
		virtual const char* GetName(){ return "MovementSystem"; }
		virtual void Initialize();

		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(IEventData const &event);

	private:
		unsigned int CalculateDirection(float x, float y);

	};
};

#endif