#pragma once

#define COM_CREATE_FN_DECL(classname)\
	static IComponent* create_## classname();

#define COM_CREATE_FN_IMPL(classname)\
	IComponent* classname::create_## classname()\
	{return new classname; }

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
