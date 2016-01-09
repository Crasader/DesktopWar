#ifndef _BULLET_COMPONENT_H_
#define _BULLET_COMPONENT_H_

#include "../Component.h"
#include "../Entity.h"
#include "gfx/gfx.h"

namespace Genius
{
	class BulletData;

	/************************************************************************/
	/*                                                BulletNormalAnimCom                      */
	/************************************************************************/
	class BulletBaseAnimCom : public Component
	{
	public:
		cocos2d::Node*				m_pAvatarRoot;
		cocostudio::Armature*		m_pBodyArmature;

	public:
		BulletBaseAnimCom(const std::string& bodyFileName);
		virtual ~BulletBaseAnimCom();
	};

	/************************************************************************/
	/*                                                BulletArrowAnimCom                      */
	/************************************************************************/
	class BulletArrowAnimCom : public BulletBaseAnimCom
	{
	public:
		const static std::string stopAnimName;

	public:
		BulletArrowAnimCom(const std::string& bodyFileName);
		
		void StayStill();
		void AnimationMovementCallback(cocostudio::Armature *cca, cocostudio::MovementEventType movType, const std::string& animName);
		void AnimationFrameCallback(cocostudio::Bone* bone, const std::string& eventName, int oriIdx, int currentIdx);
	};

	/************************************************************************/
	/*                                                BulletBombAnimCom                      */
	/************************************************************************/
	class BulletBombAnimCom : public BulletBaseAnimCom
	{
	public:
		const static std::string explodeAnimName;

	public:
		BulletBombAnimCom(const std::string& bodyFileName, const std::string& tailFileName);
		
		void StartExplode();
		void AnimationMovementCallback(cocostudio::Armature *cca, cocostudio::MovementEventType movType, const std::string& animName);
		void AnimationFrameCallback(cocostudio::Bone* bone, const std::string& eventName, int oriIdx, int currentIdx);
	};

	/************************************************************************/
	/*                                                BulletEggAnimCom                      */
	/************************************************************************/
	class BulletEggAnimCom : public BulletBaseAnimCom
	{
	public:
		BulletEggAnimCom(const std::string& bodyFileName);
		void AnimationMovementCallback(cocostudio::Armature *cca, cocostudio::MovementEventType movType, const std::string& animName);
		void AnimationFrameCallback(cocostudio::Bone* bone, const std::string& eventName, int oriIdx, int currentIdx);
	};

	/************************************************************************/
	/*                                                BulletTemplateCom                      */
	/************************************************************************/
	class BulletTemplateCom : public Component
	{
	public:
		const BulletData*	pBulletData;

		BulletTemplateCom(BulletData* _bulletInfo);
	};

	/************************************************************************/
	/*                          BulletDamageSingleCom×Óµ¯µ¥ÌåÉËº¦                      */
	/************************************************************************/
	class BulletDamageSingleCom : public Component
	{
	public:
		int		targetID;

	public:
		BulletDamageSingleCom():
			targetID(Entity::InvalidID)
		{}
	};

	/************************************************************************/
	/*                                         BulletDamageScopeCom                      */
	/************************************************************************/
	class BulletDamageScopeCom : public Component
	{
	public:
		BulletDamageScopeCom()
		{}
	};

	/************************************************************************/
	/*                                          BulletDamageNoneCom                      */
	/************************************************************************/
	class BulletDamageNoneCom : public Component
	{
	public:
		BulletDamageNoneCom()
		{}
	};

	/************************************************************************/
	/*                                           PawnDebugDrawCom                           */
	/************************************************************************/
	class BulletDebugDrawCom : public Component
	{
	public:
		cocos2d::Node*			pRoot;
		cocos2d::DrawNode*	pNodeBoxCollider;
		cocos2d::DrawNode*	pNodeHurtRange;

	public:
		BulletDebugDrawCom();
		~BulletDebugDrawCom();
		void Clear();
	};

};

#endif