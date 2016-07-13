
#pragma once

#include <string>

namespace Genius
{
	class Component;
	class Entity;
	/************************************************************************/
	/*                                �ű�ר��                                      */
	/************************************************************************/
	class EntityWrapper
	{
	public:
		EntityWrapper(Entity* ent);

		Component* AddComponent(const char* name);

		//Entity* GetEntity(){ return m_entity; }

		int GetID();

	private:
		Entity* m_entity;
	};

}
 