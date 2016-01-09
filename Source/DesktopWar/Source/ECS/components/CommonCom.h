#ifndef _COMMON_COMPONENT_H_
#define _COMMON_COMPONENT_H_

#include "../Component.h"
#include "../Entity.h"
#include "gfx/gfx.h"

namespace Genius
{
	/************************************************************************/
	/*                                           VelocityCom                           */
	/************************************************************************/
	class VelocityCom : public Component
	{
	public:
		float x;
		float y;

	public:
		VelocityCom(float _x, float _y) :
			x(_x),
			y(_y)
		{}
	};

	/************************************************************************/
	/*                                           PositionCom                           */
	/************************************************************************/
	class PositionCom : public Component
	{
	public:
		float x;
		float y;

	public:
		PositionCom(float _x, float _y):
			x(_x),
			y(_y)
		{}
	};

	/************************************************************************/
	/*                                           BoxColliderCom                           */
	/************************************************************************/
	class BoxColliderCom : public Component
	{
	public:
		bool	positive;		// 主动进行碰撞计算，true用在例如子弹，false用在pawn.
		float centerX;
		float centerY;
		float width;
		float height;

		const static int MaxCount = 16;
		int	collideIDs[MaxCount];
		int	areaID;		// 分区进行彭转检测，减少计算

	public:
		BoxColliderCom(bool _positive, float _centerX, float _centerY, float _width, float _height) :
			positive(_positive),
			centerX(_centerX),
			centerY(_centerY),
			width(_width),
			height(_height),
			areaID(0)
		{
			for (int i = 0; i < MaxCount; ++i)
				collideIDs[i] = Entity::InvalidID;
		}
	};

	/************************************************************************/
	/*                                           ColliderListenerCom                           */
	/************************************************************************/
	class ColliderHandlerCom : public Component
	{
	public:
		std::function<void(int, int)> _enterColliderListener;
		std::function<void(int, int)> _exitColliderListener;

	public:
		ColliderHandlerCom(std::function<void(int, int)> _enterFunc, std::function<void(int, int)> _exitFunc) :
			_enterColliderListener(_enterFunc),
			_exitColliderListener(_exitFunc)
		{}
		~ColliderHandlerCom(){}
	};

	/************************************************************************/
	/*                                           TeamCom                           */
	/************************************************************************/
	class TeamCom : public Component
	{
	public:
		int team;

	public:
		TeamCom(int _team):
			team(_team)
		{}
	};

	/************************************************************************/
	/*                                           TargetCom                           */
	/************************************************************************/
	class TargetCom : public Component
	{
	public:
		int		targetType;
		int		targetID;
		float		targetX;
		float		targetY;

	public:
		TargetCom(int _type, int _id = Entity::InvalidID, float _x = 0, float _y = 0) :
			targetType(_type),
			targetID(_id),
			targetX(_x),
			targetY(_y)
		{}
	};

	/************************************************************************/
	/*                                           SimpleAnimationCom                           */
	/************************************************************************/
	class SimpleAnimationCom : public Component
	{
	public:
		cocos2d::Node*					m_pAvatarRoot;
		cocostudio::Armature*		m_pBodyArmature;

	public:
		SimpleAnimationCom(const std::string& fileName);
		~SimpleAnimationCom();
	};

	/************************************************************************/
	/*                                           ParticleCom                           */
	/************************************************************************/
	class ParticleCom : public Component
	{
	public:
		cocos2d::Node*					m_pAvatarRoot;

	public:
		ParticleCom(const std::string& fileName);
		~ParticleCom();
	};

	/************************************************************************/
	/*                                                BezierMovingCom                      */
	/************************************************************************/
	class BezierMovingCom : public Component
	{
	public:
		float controlPoint1X;		// 相对startX
		float controlPoint1Y;		// 相对startY
		float controlPoint2X;		// 相对startX
		float controlPoint2Y;		// 相对startY

		float startX;
		float startY;
		float deltaX;
		float deltaY;

		float duration;
		float timePassed;

	public:
		BezierMovingCom(float _startx, float _starty, float _destx, float _desty, float _duration) :
			startX(_startx),
			startY(_starty),
			deltaX(_destx - _startx),
			deltaY(_desty - _starty),
			controlPoint1X(0),
			controlPoint1Y(100),
			controlPoint2X(_destx - _startx),
			controlPoint2Y(100),
			duration(_duration),
			timePassed(0)
		{}

		bool IsDone(){ return timePassed >= duration; }
		void Stop(){ timePassed = duration; }
	};

	/************************************************************************/
	/*                                                TrackingMovingCom                      */
	/************************************************************************/
	class DelayTrackMovingCom : public Component
	{
	public:
		int		targetEntityID;
		float		lifeTime;
		float		delayTime;
		float		targetCachePosX;
		float		targetCachePosY;
		bool		isTracking;

	public:
		DelayTrackMovingCom(int _targetID, float _delayTime) :
			targetEntityID(_targetID),
			lifeTime(0),
			delayTime(_delayTime),
			targetCachePosX(1500),
			targetCachePosY(100),
			isTracking(true)
		{}

		virtual bool Init();
	};
};

#endif