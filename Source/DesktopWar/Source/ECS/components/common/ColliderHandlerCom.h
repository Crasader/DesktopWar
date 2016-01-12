
#pragma once


#include "../../core/Component.h"


namespace Genius
{

	class ColliderHandlerCom : public Component
	{
	public:
		std::function<void(int, int)> _enterColliderListener;
		std::function<void(int, int)> _exitColliderListener;

	public:
		ColliderHandlerCom(std::function<void(int, int)> _enterFunc, std::function<void(int, int)> _exitFunc) :
			_enterColliderListener(_enterFunc),
			_exitColliderListener(_exitFunc)
		{}
		~ColliderHandlerCom(){}
	};

};
