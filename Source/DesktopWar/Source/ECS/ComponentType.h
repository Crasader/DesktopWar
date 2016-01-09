#pragma once

#include <bitset>
#include "BitSize.h"

namespace Genius
{
	class ComponentType
	{
		/**
		 * Identifies a bitset and id for a component object
		 * Do not instantiate a ComponentType, instead use the ComponentTypeManager.
		 * */

	public:
		ComponentType();
		//==================================
		std::bitset<BITSIZE> getBit() const;
		int GetId() const;
	private:
		//
		static std::bitset<BITSIZE> nextBit;
		static int nextId;
		//==================================
		std::bitset<BITSIZE> bit;
		int id;
		void init();
	};
};
