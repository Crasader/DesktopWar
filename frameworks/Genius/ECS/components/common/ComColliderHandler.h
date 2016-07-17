
#pragma once


#include "../../core/IComponent.h"
#include <functional>

namespace Genius
{

	class ComColliderHandler : public IComponent
	{
	public:
		COM_CREATE_FN_DECL(ComColliderHandler);

	public:
		std::function<void(int, int)> _enterColliderListener;
		std::function<void(int, int)> _exitColliderListener;

	public:
		ComColliderHandler();
		void Create(std::function<void(int, int)> _enterFunc, std::function<void(int, int)> _exitFunc);

	};

};
