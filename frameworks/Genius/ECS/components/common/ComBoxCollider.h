
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
		bool	positive;		// ����������ײ���㣬true���������ӵ���false����pawn.
		float centerX;
		float centerY;
		float width;
		float height;

		const static int MaxCount = 16;
		int	collideIDs[MaxCount];
		int	areaID;		// ����������ת��⣬���ټ���

	public:
		void Create(bool _positive, float _centerX, float _centerY, float _width, float _height);

	};

};