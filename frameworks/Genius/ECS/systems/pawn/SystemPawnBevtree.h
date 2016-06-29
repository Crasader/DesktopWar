#ifndef _BEVTREE_SYSTEM_H_
#define _BEVTREE_SYSTEM_H_

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"
#include "../../components/pawn/ComPawnBevtree.h"

namespace Genius
{
	class SystemPawnBevtree : public EntityProcessingSystem
	{
	private:
		ComponentMapper<ComPawnBevtree> bevtreeMapper;

	public:
		SystemPawnBevtree()
		{
			SetComponentTypes<ComPawnBevtree>();
		}
		virtual const char* GetName(){ return "SystemPawnBevtree"; }
		virtual void Initialize();

		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(IEventData const &event);

	};
};
#endif