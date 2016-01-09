#ifndef _BEVTREE_SYSTEM_H_
#define _BEVTREE_SYSTEM_H_

#include "../EntityProcessingSystem.h"
#include "../ComponentMapper.h"
#include "../components/BevtreeCom.h"

namespace Genius
{
	class BevtreeSystem : public EntityProcessingSystem
	{
	private:
		ComponentMapper<BevtreeCom> bevtreeMapper;

	public:
		BevtreeSystem()
		{
			SetComponentTypes<BevtreeCom>();
		}
		virtual const char* GetName(){ return "BevtreeSystem"; }
		virtual void Initialize();

		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(IEventData const &event);

	};
};
#endif