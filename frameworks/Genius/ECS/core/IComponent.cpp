
#include "IComponent.h"

namespace Genius
{

	IComponent::IComponent() :
		entity(nullptr)
	{
	}

	IComponent::~IComponent()
	{

	}

	void IComponent::SetEntity(Entity* ent)
	{
		entity = ent;
	}

	Entity* IComponent::GetEntity()
	{
		return entity;
	}

};
