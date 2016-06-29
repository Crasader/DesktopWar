
#pragma once


#include "../../core/Component.h"
#include <functional>

namespace Genius
{

	class ComColliderHandler : public Component
	{
	public:
		std::function<void(int, int)> _enterColliderListener;
		std::function<void(int, int)> _exitColliderListener;

	public:
		ComColliderHandler(std::function<void(int, int)> _enterFunc, std::function<void(int, int)> _exitFunc) :
			_enterColliderListener(_enterFunc),
			_exitColliderListener(_exitFunc)
		{}
		~ComColliderHandler(){}
	};

};
