#pragma once

#include <typeinfo>
#include <bitset>
#include <unordered_map>
#include "BitSize.h"

namespace Genius
{

	class EntitySystem;

	class SystemBitManager
	{
	private:
		static int POS;
		static std::unordered_map< size_t, std::bitset<BITSIZE>* > systemBits;

	public:
		static void RemoveBitSets();

		static std::bitset<BITSIZE> & GetBitFor(const std::type_info & type);
		
		template<typename system>
		static std::bitset<BITSIZE> & GetBitFor()
		{
			assert((std::is_base_of< EntitySystem, system >::value == true));
			return GetBitFor(typeid(system));
		}

	};

};
