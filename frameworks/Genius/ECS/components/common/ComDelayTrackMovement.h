
#pragma once


#include "../../core/IComponent.h"


namespace Genius
{
	
	class ComDelayTrackMovement : public IComponent
	{
	public:
		COM_CREATE_FN_DECL(ComDelayTrackMovement);

	public:
		const static int Wait = 1;
		const static int FindTarget = 2;
		const static int AdjustDirection = 3;
		const static int Explode = 4;

	public:
		int		targetEntityID;
		float		lifeTime;
		float		delayTime;
		float		targetCachePosX;
		float		targetCachePosY;
		bool		isTracking;
		int		currentState;

	public:
		ComDelayTrackMovement();
		virtual void OnAwake();

	};
	
};
