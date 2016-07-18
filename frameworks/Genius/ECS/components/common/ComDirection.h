
#pragma once


#include "../../core/IComponent.h"

/************************************************************************/
/*         该组件让render旋转使之指向移动方向（例如箭的运动）                        */
/************************************************************************/

namespace Genius
{

	class ComDirection : public IComponent
	{
	public:
		COM_CREATE_FN_DECL(ComDirection);
	};

};
