#pragma once

#include "EntityManager.h"
#include "ECSWorld.h"

namespace Genius
{

	template<typename c>
	class ComponentMapper
	{

	private:

		EntityManager * em;

	public:

		~ComponentMapper()
		{
			//Not the owner. Only a pointer to.
			em = nullptr;
		}

		void init(ECSWorld& world)
		{
			em = world.GetEntityManager();
		}

		/**
		 *Returns the component mapped to the Entity.
		 *If there is no such component associated with the entity
		 *nullptr is returned.
		 */
		c * get(Entity* e)
		{
			//ATTN perhaps pointing to the component bag is faster.
			return (c*)em->GetComponent<c>(e);
		}

	};
};
