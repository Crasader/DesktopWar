#ifndef _PAWNACTION_COMPONENT_H_
#define _PAWNACTION_COMPONENT_H_

#include <string>
#include <vector>
#include "../Component.h"
#include "pawn/PawnDefines.h"
#include "common/2Ddef.h"
#include "gfx/gfx.h"

namespace Genius
{
	class RoleData;

	/************************************************************************/
	/*                                           PawnAnimCom                           */
	/************************************************************************/
	class PawnAnimCom : public cocos2d::Ref, public Component
	{
	public:
		cocos2d::Node*					m_pAvatarRoot;
		cocostudio::Armature*			m_pBodyArmature;
		UIBar*									m_pLifeBar;
		Label*									m_pDebugLabel;
		ActionType							m_curAction;

	public:
		PawnAnimCom(int roleID);
		virtual ~PawnAnimCom();

		float GetWidth();
		float GetHeight();
		void PlayAnimation(std::string name);
		void SetPosition(float x, float y);
		bool HaveThisAnimation(std::string name);
		void PlayFloatNumber(int number, int y);

		void SetDebugLabel(std::string text);

	public:
		void AnimationMovementCallback(cocostudio::Armature *cca, cocostudio::MovementEventType met, const std::string& cr);
		void AnimationFrameCallback(cocostudio::Bone* bone, const std::string& eventName, int oriIdx, int currentIdx);
	};

	/************************************************************************/
	/*                                           PawnActionCom                           */
	/************************************************************************/
	class PawnActionCom : public Component
	{
	public:
		unsigned int		m_curAction;

	public:
		PawnActionCom(unsigned int act);

		void StartAction(unsigned int act);
	};

	/************************************************************************/
	/*                                           PawnDirectionCom                           */
	/************************************************************************/
	class PawnDirectionCom : public Component
	{
	public:
		unsigned int	m_faceDir;
		unsigned int	m_lastFaceDir;

	public:
		PawnDirectionCom()
		{
			m_lastFaceDir = Face_Left;
			m_faceDir = Face_Left;
		}
	};

	/************************************************************************/
	/*                                           PawnTemplateCom                           */
	/************************************************************************/
	class PawnTemplateCom : public Component
	{
	public:
		const RoleData*	pRoleData;

		PawnTemplateCom(int roleID);

	};

	/************************************************************************/
	/*                                           PawnNavigationCom                           */
	/************************************************************************/
	class PawnNavigationCom : public Component
	{
	public:
		std::vector<Point2D>	pathPoints;
		unsigned int					curPointIndex;
		bool									arrived;
	public:
		PawnNavigationCom() :
			curPointIndex(0),
			arrived(false)
		{}

		void MoveTo(float x, float y);
	};

	/************************************************************************/
	/*                                           PawnAttributeCom                           */
	/************************************************************************/
	class PawnAttributeCom : public Component
	{
	public:
		int		curLife;
	
	public:
		PawnAttributeCom(int roleID);
		~PawnAttributeCom();
	};

	/************************************************************************/
	/*                                           PawnFightCom                           */
	/************************************************************************/
	class PawnFightCom : public Component
	{
	public:
		int		enemyID;
		bool		haveTarget;
		bool		isTargetInNearRange;
		bool		isTargetInFarRange;

	public:
		PawnFightCom();
		~PawnFightCom();
		virtual bool Init();
	};

	/************************************************************************/
	/*                                           PawnDebugDrawCom                           */
	/************************************************************************/
	class PawnDebugDrawCom : public Component
	{
	public:
		cocos2d::Node*			pRoot;
		cocos2d::DrawNode*	pNodeBoxCollider;
		cocos2d::DrawNode*	pNodeNearRange;
		cocos2d::DrawNode*	pNodeFarRange;

	public:
		PawnDebugDrawCom();
		~PawnDebugDrawCom();
		void Clear();
	};

};

#endif