
#pragma once


#include "../../core/IComponent.h"
#include <functional>

namespace Genius
{

	class ComColliderHandler : public IComponent
	{
	public:
		std::function<void(int, int)> _enterColliderListener;
		std::function<void(int, int)> _exitColliderListener;

	public:
		void Create(std::function<void(int, int)> _enterFunc, std::function<void(int, int)> _exitFunc);

	};

};
