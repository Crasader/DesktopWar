
#pragma once

#include <string>
#include "../core/Component.h"

namespace Genius
{

	class ComEntityScript : public Component
	{
	public:
		int script;

	public:
		ComEntityScript();
		~ComEntityScript();
		virtual bool Init();
	};

};
