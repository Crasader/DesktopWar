
#pragma once


#include "../../core/IComponent.h"


namespace Genius
{
	
	class ComDelayTrackMovement : public IComponent
	{
	public:
		COM_CREATE_FN_DECL(ComDelayTrackMovement);

	public:
		enum
		{
			Error,
			Wait,
			FindTarget,
			AdjustDirection,
			SpeedUp,
			Explode,
		};

	public:
		int		targetEntityID;
		float		lifeTime;
		float		delayTime;
		float		targetCachePosX;
		float		targetCachePosY;
		bool		shouldTurnLeft;
		int		currentState;

	public:
		ComDelayTrackMovement();
		virtual void OnAwake();

	};
	
};
