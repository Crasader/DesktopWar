#pragma once

#include <bitset>
#include <string>
#include <cstddef>
#include <typeinfo>
#include "BitSize.h"
#include "ImmutableBag.h"
#include "EntityManager.h"
#include "ComponentTypeManager.h"

namespace Genius
{
	class Component;
	class ComponentType;
	class ECSWorld;
	
	class Entity
	{
	private:
		int								m_id;
		long int							m_uniqueId;
		std::bitset<BITSIZE>		m_typeBits;
		std::bitset<BITSIZE>		m_systemBits;
		ECSWorld*					m_pWorld;
		EntityManager*			m_pEntityManager;

		Entity(const Entity&) = delete;
		Entity& operator=(const Entity&) = delete;

	public:
		const static int InvalidID = -1;

	public:
		Entity(ECSWorld * world, int id);
		~Entity();
		int					GetId();
		void					SetUniqueId(long int uniqueId);
		long int				GetUniqueId();

		std::bitset<BITSIZE> GetTypeBits();
		void					AddTypeBit(std::bitset<BITSIZE> bit);
		void					RemoveTypeBit(std::bitset<BITSIZE> bit);
		std::bitset<BITSIZE> GetSystemBits();
		void					AddSystemBit(std::bitset<BITSIZE> bit);
		void					RemoveSystemBit(std::bitset<BITSIZE> bit);
		void					SetSystemBits(std::bitset<BITSIZE> systemBits);
		void					SetTypeBits(std::bitset<BITSIZE> typeBits);
		void					Reset();

		std::string			ToString();

		Component*		AddComponent(Component * c);

		//Might change to non template
		template<typename c>
		void RemoveComponent()
		{
			m_pEntityManager->RemoveComponent(*this, ComponentTypeManager::getTypeFor<c>());
		}

		void					RemoveComponent(ComponentType & type);
		Component*		GetComponent(ComponentType & type);

		template<typename c>
		c * GetComponent()
		{
			return (c*)m_pEntityManager->GetComponent(this, ComponentTypeManager::getTypeFor<c>());
		}

		ImmutableBag<Component*>& GetComponents();

		bool					IsActive();
		void					Refresh();
		void					Remove();
		void					SetGroup(std::string group);
		void					SetTag(std::string tag);
	};

};
