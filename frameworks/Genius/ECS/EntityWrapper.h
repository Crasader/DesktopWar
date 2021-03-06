
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
		Entity* GetEntity();
		IComponent* AddComponent(const char* name);
		void AddTag(const char* tag);
		void RemoveTag(const char* tag);

		void OnDestroy();

	private:
		Entity* m_entity;
	};

}
 