// d:)
#include "SystemBitManager.h"

namespace Genius
{
	int SystemBitManager::POS = 0;
	std::unordered_map<size_t, std::bitset<BITSIZE>*> SystemBitManager::systemBits;

	void SystemBitManager::RemoveBitSets()
	{
		std::unordered_map< size_t, std::bitset<BITSIZE>* >::iterator it;

		for (it = systemBits.begin(); it != systemBits.end(); it++)
		{
			delete it->second;
		}
		systemBits.clear();
		POS = 0;
	}

	std::bitset<BITSIZE> & SystemBitManager::GetBitFor(const std::type_info & type)
	{

		//assert((std::is_base_of< EntitySystem, system >::value == true));

		size_t hash = type.hash_code();

		std::bitset<BITSIZE> * bit = systemBits[hash];

		if (bit == nullptr)
		{

			bit = new std::bitset<BITSIZE>(1);
			(*bit) <<= POS++;

			systemBits[hash] = bit;
		}

		return *bit;

	}
}
