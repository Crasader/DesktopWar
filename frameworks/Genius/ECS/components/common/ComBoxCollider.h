
#pragma once


#include "../../core/Component.h"
#include "../../core/Entity.h"


namespace Genius
{

	class ComBoxCollider : public Component
	{
	public:
		bool	positive;		// ����������ײ���㣬true���������ӵ���false����pawn.
		float centerX;
		float centerY;
		float width;
		float height;

		const static int MaxCount = 16;
		int	collideIDs[MaxCount];
		int	areaID;		// ����������ת��⣬���ټ���

	public:
		ComBoxCollider(bool _positive, float _centerX, float _centerY, float _width, float _height) :
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