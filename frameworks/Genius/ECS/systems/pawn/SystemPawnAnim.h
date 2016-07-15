#ifndef _PAWN_ANIM_SYSTEM_H_
#define _PAWN_ANIM_SYSTEM_H_

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"

#include "../../components/common/ComTransform.h"
#include "../../components/pawn/ComPawnAnim.h"


#include "../../../common/2Ddef.h"
#include "../../../pawn/PawnDefines.h"

namespace Genius
{
	class SystemPawnAnim : public EntityProcessingSystem
	{
	private:
		ComponentMapper<ComPawnAnim>	pawnAnimMapper;
		ComponentMapper<ComTransform>		transMapper;

	public:
		SystemPawnAnim()
		{
			SetComponentTypes<ComPawnAnim, ComTransform>();
		}
		virtual const char* GetName(){ return "SystemPawnAnim"; }
		virtual void Initialize();

		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(IEventData const &event);

	};
};

#endif