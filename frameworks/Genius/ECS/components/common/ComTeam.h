
#pragma once


#include "../../core/Component.h"

namespace Genius
{

	class ComTeam : public Component
	{
	public:
		int team;

	public:
		ComTeam(int _team):
			team(_team)
		{}
	};

};

