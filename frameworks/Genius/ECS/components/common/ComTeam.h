
#pragma once


#include "../../core/IComponent.h"

namespace Genius
{

	class ComTeam : public IComponent
	{
	public:
		int team;

	public:
		void SetTeam(int t)
		{
			team = t;
		}
	};

};

