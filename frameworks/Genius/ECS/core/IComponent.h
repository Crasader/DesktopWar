#pragma once


namespace Genius
{
	class Entity;
	class EntityManager;
	class IComponent
	{
		friend class EntityManager;
	public:
		virtual ~IComponent() = 0;
		virtual bool	Init(){ return true; }
		Entity*			GetOwner(){ return m_pEntity; }
		

	protected:
		IComponent() :
			m_pEntity(nullptr)
		{};
		void				SetOwner(Entity* ent){ m_pEntity = ent; }

	private:
		Entity*		m_pEntity;
	};

};
