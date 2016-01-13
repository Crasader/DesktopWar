
#pragma once


#include "../../core/Component.h"


namespace Genius
{

	class ComPawnAction : public Component
	{
	public:
		unsigned int		m_curAction;

	public:
		ComPawnAction(unsigned int act);

		void StartAction(unsigned int act);
	};

	

};
