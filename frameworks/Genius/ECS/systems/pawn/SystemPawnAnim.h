#ifndef _PAWN_ANIM_SYSTEM_H_
#define _PAWN_ANIM_SYSTEM_H_

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"

#include "../../components/common/ComPosition.h"
#include "../../components/pawn/ComPawnAnim.h"
#include "../../components/pawn/ComPawnDirection.h"

#include "../../../common/2Ddef.h"
#include "../../../pawn/PawnDefines.h"

namespace Genius
{
	class SystemPawnAnim : public EntityProcessingSystem
	{
	private:
		ComponentMapper<ComPawnAnim>	pawnAnimMapper;
		ComponentMapper<ComPosition>		positionMapper;
		ComponentMapper<ComPawnDirection>	pawnDirectionMapper;

	public:
		SystemPawnAnim()
		{
			SetComponentTypes<ComPawnAnim, ComPosition, ComPawnDirection>();
		}
		virtual const char* GetName(){ return "SystemPawnAnim"; }
		virtual void Initialize();

		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(IEventData const &event);

	/*private:
		void PlayAnimation(ComPawnAnim* animCom, ComPawnDirection* dirCom, ActionType act);

		void PlayIdle(ComPawnAnim* animCom, ComPawnDirection* dirCom);
		void PlayDie(ComPawnAnim* animCom, ComPawnDirection* dirCom);
		void PlayMove(ComPawnAnim* animCom, ComPawnDirection* dirCom);
		void PlayAtkNear(ComPawnAnim* animCom, ComPawnDirection* dirCom);
		void PlayAtkNear2(ComPawnAnim* animCom, ComPawnDirection* dirCom);
		void PlayAtkFar(ComPawnAnim* animCom, ComPawnDirection* dirCom);
		void PlaySkill1(ComPawnAnim* animCom, ComPawnDirection* dirCom);
		void PlaySkill2(ComPawnAnim* animCom, ComPawnDirection* dirCom);
		void PlaySkill3(ComPawnAnim* animCom, ComPawnDirection* dirCom);*/
	};
};

#endif