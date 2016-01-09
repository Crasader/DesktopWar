#ifndef _GENIUS_USERACTIONS_H_
#define _GENIUS_USERACTIONS_H_

#include "Buff.h"
#include "BuffAction.h"

namespace Genius
{

	class UserActions
	{
	public:
		static BuffActionFunction FindAction(std::string& name);
	};

};

#endif