
#pragma once


#include "../../core/Component.h"


namespace Genius
{
	
	class ComDelayTrackMoving : public Component
	{
	public:
		int		targetEntityID;
		float		lifeTime;
		float		delayTime;
		float		targetCachePosX;
		float		targetCachePosY;
		bool		isTracking;

	public:
		ComDelayTrackMoving(int _targetID, float _delayTime) :
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
