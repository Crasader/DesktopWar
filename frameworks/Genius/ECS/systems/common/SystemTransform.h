#ifndef _MOVEMENT_SYSTEM_H_
#define _MOVEMENT_SYSTEM_H_

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"
#include "../../components/common/ComTransform.h"

namespace Genius
{
	class SystemTransform : public EntityProcessingSystem
	{
	private:
		ComponentMapper<ComTransform> transMapper;

	public:
		SystemTransform()
		{
			SetComponentTypes<ComTransform>();
		}
		virtual const char* GetName(){ return "SystemTransform"; }
		virtual void Initialize();

		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(IEventData const &event);

	private:
		unsigned int CalculateDirection(float x, float y);

	};
};

#endif