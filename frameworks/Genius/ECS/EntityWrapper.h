
#pragma once

#include <string>

namespace Genius
{
	class IComponent;
	class Entity;
	/************************************************************************/
	/*                                �ű�ר��                                      */
	/************************************************************************/
	class EntityWrapper
	{
	public:
		EntityWrapper(Entity* ent);

		IComponent* AddComponent(const char* name);

		//Entity* GetEntity(){ return m_entity; }

		int GetID();

	private:
		Entity* m_entity;
	};

}
 