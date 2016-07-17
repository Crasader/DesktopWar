
#pragma once


#include "../../core/IComponent.h"


namespace Genius
{
	
	class ComDelayTrackMoving : public IComponent
	{
	public:
		COM_CREATE_FN_DECL(ComDelayTrackMoving);

	public:
		int		targetEntityID;
		float		lifeTime;
		float		delayTime;
		float		targetCachePosX;
		float		targetCachePosY;
		bool		isTracking;

	public:
		void Create(int _targetID, float _delayTime);

		virtual void OnAwake();
	};
	
};
