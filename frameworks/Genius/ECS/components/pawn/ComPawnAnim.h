
#pragma once

#include <string>
#include "../../core/IComponent.h"
#include "common/2Ddef.h"
#include "gfx/gfx.h"
#include "pawn/action/ActionHandler.h"

namespace Genius
{
	enum eAnimFsmType
	{
		AFT_Simple = 1,
	};

	class AnimSet;
	class AnimFSM;

	class ComPawnAnim : public IComponent, public ActionHandler, public cocos2d::Ref
	{
	public:
		COM_CREATE_FN_DECL(ComPawnAnim);

	public:
		AnimSet*								m_pAnimSet;
		AnimFSM*							m_pAnimFsm;
		cocos2d::Node*					m_pAvatarRoot;
		cocostudio::Armature*			m_pBodyArmature;
		UIBar*									m_pLifeBar;
		cocos2d::Label*					m_pDebugLabel;
		int										m_curAction;

	public:
		void Create(int roleID);
		virtual ~ComPawnAnim();

		virtual void OnAwake();
		virtual void OnDestroy();
		virtual void HandleAction(PawnAction* pAction);

		float GetWidth();
		float GetHeight();
		void PlayAnimation(const std::string& name);
		void SetPosition(float x, float y);
		bool HaveThisAnimation(std::string name);
		void PlayFloatNumber(int number, int y);

		void SetDebugLabel(std::string text);

	public:
		void AnimationMovementCallback(cocostudio::Armature *cca, cocostudio::MovementEventType met, const std::string& cr);
		void AnimationFrameCallback(cocostudio::Bone* bone, const std::string& eventName, int oriIdx, int currentIdx);

	private:
		void CreateAnimFSM(int fsmType);

	};

	

};
