
#pragma once

#include <string>

namespace Genius
{
	class IComponent;
	class Entity;
	/************************************************************************/
	/*                                ½Å±¾×¨ÓÃ                                      */
	/************************************************************************/
	class EntityWrapper
	{
	public:
		EntityWrapper(Entity* ent);
		~EntityWrapper();
		IComponent* AddComponent(const char* name);
		void AddTag(const char* tag);
		void RemoveTag(const char* tag);
		int GetID();

	private:
		Entity* m_entity;
	};

}
 