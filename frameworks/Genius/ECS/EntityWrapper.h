
#pragma once

namespace Genius
{
	class Component;
	/************************************************************************/
	/*                                �ű�ר��                                      */
	/************************************************************************/
	class EntityWrapper
	{
	public:
		Component* AddTransform();
		Component* AddPawnAnim();
		Component* AddPawnAgent();

	};

}
 