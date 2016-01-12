#pragma once

#include <bitset>
#include "BitSize.h"
#include "Component.h"
#include <iostream>
#include <assert.h>
#include <typeinfo>
#include <bitset>
#include "ImmutableBag.h"
#include "ComponentTypeManager.h"


namespace Genius
{

	class Entity;
	class ECSWorld;

	class EntitySystem
	{
	private:
		//Meta templates. Helps with passing each type from the variadic template
		//Struct to pass rest the types
		template<typename...>
		struct typelist {};

	public:
		virtual ~EntitySystem();

		std::bitset<BITSIZE> GetSystemBit(){return m_systemBit;}
		void							SetSystemBit(std::bitset<BITSIZE> bit);

		virtual void				Initialize() {};
		virtual const char*	GetName(){ return "sys name"; }
		void							Change(Entity* e);
		void							Process();

		void							SetWorld(ECSWorld *world);
		int							GetEntityCount();
		Bag<Entity*>&			GetActivities(){ return m_activities; }
		bool							IsMyEntity(Entity* e);

	protected:
		EntitySystem() { this->world = nullptr; };
		
		/**
		 * Call this in the constructor of the derived system
		 */
		template<typename...components>
		void SetComponentTypes()
		{
			AddToTypeFlags(typelist<components...>());
		}
		/**
		 * Call this in the constructor of the derived system
		 */
		template<typename...components>
		void ExcludeComponentTypes()
		{
			AddToExcludedTypeFlags(typelist<components...>());
		}

		/*override these functions*/
		virtual void			Begin() {};
		virtual void			End() {};
		virtual void			Removed(Entity* e) {};
		virtual void			Added(Entity* e) {};

		//Abstracts
		virtual void			ProcessEntities(ImmutableBag<Entity*> & bag) = 0;
		virtual bool			CheckProcessing() = 0;

	private:
		void						remove(Entity* e);
		
		/*
		 * Recursively called. On each iteration  "component" is set to the next "typename" from rest pack set. .
		 * We pass this component into our ComponentManager.
		 */
		template<typename component, typename ... Rest>
		void AddToTypeFlags(typelist<component, Rest...>)
		{
			//Add Bits to typeflags
			m_typeFlags |= ComponentTypeManager::getBit<component>();
			AddToTypeFlags(typelist<Rest...>());
		};

		/**
		 * addToTypeFlag is called recursively. This defines the end condition.
		 * When our typelist has no types left from the pack, the call will end.
		 */
		void AddToTypeFlags(typelist<>) { };

		//Exclude
		template<typename component, typename ... Rest>
		void AddToExcludedTypeFlags(typelist<component, Rest...>)
		{
			m_excludedTypeFlags |= ComponentTypeManager::getBit<component>();
			AddToExcludedTypeFlags(typelist<Rest...>());
		};

		void AddToExcludedTypeFlags(typelist<>) { };

	protected:
		ECSWorld * world;

	private:
		std::bitset<BITSIZE>			m_systemBit;
		std::bitset<BITSIZE>			m_typeFlags;
		std::bitset<BITSIZE>			m_excludedTypeFlags;
		Bag<Entity*>					m_activities;
	};

};