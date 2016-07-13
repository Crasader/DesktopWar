#pragma once

#include <unordered_map>
#include <typeinfo>
#include <assert.h>
#include <bitset>
#include "ComponentType.h"
#include "IComponent.h"

namespace Genius
{
	/**
	 * Manages the id and bitset for every component based on their type.
	 * */
	class ComponentTypeManager
	{

	private:
		ComponentTypeManager();
		static std::unordered_map<size_t, ComponentType*> componentTypes;

	public:
		static void deleteComponentTypes();
		static ComponentType & getTypeFor(const std::type_info &t);

		/**
		* Gets the component type object
		**/
		template<typename c>
		static ComponentType & getTypeFor()
		{

			//Check if we are being legal with components and shizzle
			//Component * c = (component*)0;

			assert((std::is_base_of<IComponent, c >::value == true));

			return getTypeFor(typeid(c));
		}

		/**
		* Gets the bit set of a component
		**/
		template<typename c>
		static std::bitset<BITSIZE> getBit()
		{

			//Check if we are being legal with components and shizzle
			//Component * c = (component*)0;

			assert((std::is_base_of< IComponent, c >::value == true));
			return getTypeFor(typeid(c)).getBit();
		}

		/**
		 * Gets the component id
		 **/
		template<typename c>
		static int GetId()
		{
			//Check if we are being legal with components and shizzle
			assert((std::is_base_of< IComponent, c >::value == true));
			return getTypeFor(typeid(c)).GetId();
		};
	};
}
