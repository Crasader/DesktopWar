
#pragma once


#include "../../core/IComponent.h"
#include "../../core/Entity.h"


namespace Genius
{

	class ComBoxCollider : public IComponent
	{
	public:
		COM_CREATE_FN_DECL(ComBoxCollider);

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
		void Create(bool _positive, float _centerX, float _centerY, float _width, float _height);

	};

};