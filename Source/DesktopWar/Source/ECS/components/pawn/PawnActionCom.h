
#pragma once


#include "../../core/Component.h"


namespace Genius
{

	class PawnActionCom : public Component
	{
	public:
		unsigned int		m_curAction;

	public:
		PawnActionCom(unsigned int act);

		void StartAction(unsigned int act);
	};

	

};
