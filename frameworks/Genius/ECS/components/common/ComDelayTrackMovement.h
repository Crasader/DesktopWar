
#pragma once


#include "../../core/IComponent.h"


namespace Genius
{
	
	class ComDelayTrackMovement : public IComponent
	{
	public:
		COM_CREATE_FN_DECL(ComDelayTrackMovement);

	public:
		int		targetEntityID;
		float		lifeTime;
		float		delayTime;
		float		targetCachePosX;
		float		targetCachePosY;
		bool		isTracking;

	public:
		ComDelayTrackMovement();
		void Create(int _targetID, float _delayTime);

		virtual void OnAwake();
	};
	
};
