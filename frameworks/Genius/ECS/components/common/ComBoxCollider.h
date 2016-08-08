
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
		bool	isStatic;		// 静止的collider
		float centerX;
		float centerY;
		float width;
		float height;

		int	areaID;		// 分区进行彭转检测，减少计算

	public:
		virtual void OnAwake();
		void Create(bool _positive, float _centerX, float _centerY, float _width, float _height);
		float GetWidth(){ return width; }
		float GetHeight(){ return height; }
	};

};