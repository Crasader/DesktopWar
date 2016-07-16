
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
		~EntityWrapper();
		int GetID();
		IComponent* AddComponent(const char* name);
		void AddTag(const char* tag);
		void RemoveTag(const char* tag);
		

	private:
		Entity* m_entity;
	};

}
 