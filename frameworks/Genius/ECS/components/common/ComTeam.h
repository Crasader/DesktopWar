
#pragma once


#include "../../core/IComponent.h"

namespace Genius
{

	class ComTeam : public IComponent
	{
	public:
		COM_CREATE_FN_DECL(ComTeam);

	public:
		int team;

	public:
		void SetTeam(int t)
		{
			team = t;
		}
	};

};

