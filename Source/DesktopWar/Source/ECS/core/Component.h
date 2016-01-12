#pragma once

namespace Genius
{
	class Entity;
	class EntityManager;
	class Component
	{
		friend class EntityManager;
	public:
		virtual ~Component() = 0;
		virtual bool	Init(){ return true; }
		Entity*			GetOwner(){ return m_pEntity; }
		

	protected:
		Component() :
			m_pEntity(nullptr)
		{};
		void				SetOwner(Entity* ent){ m_pEntity = ent; }

	private:
		Entity*		m_pEntity;
	};

};
