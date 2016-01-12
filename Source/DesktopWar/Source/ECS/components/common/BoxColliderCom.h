
#pragma once


#include "../../core/Component.h"
#include "../../core/Entity.h"


namespace Genius
{

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

};