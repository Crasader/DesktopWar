
#pragma once


#include "../../core/Component.h"

namespace Genius
{

	class TeamCom : public Component
	{
	public:
		int team;

	public:
		TeamCom(int _team):
			team(_team)
		{}
	};

};

