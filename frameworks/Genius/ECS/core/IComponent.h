#pragma once

#define COM_CREATE_FN_DECL(classname)\
	static IComponent* create_inst();

#define COM_CREATE_FN_IMPL(classname)\
	IComponent* classname::create_inst()\
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

		virtual void	OnAwake(){}

		virtual void	OnDestroy(){}

		Entity*			GetEntity();
		
	protected:
		IComponent();

		void SetEntity(Entity* ent);

	private:
		Entity*		entity;

	};

};
