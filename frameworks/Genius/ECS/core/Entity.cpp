
#include "Entity.h"
#include <sstream>
#include "Component.h"
#include "ECSWorld.h"
//#include "EntityManager.h"

using namespace std;

namespace Genius
{

	Entity::Entity(ECSWorld * world, int id)
	{
		m_pWorld = world;
		m_pEntityManager = world->GetEntityManager();
		m_id = id;
	}

	Entity::~Entity()
	{
		m_pWorld = nullptr;
		m_pEntityManager = nullptr;
	}


	void Entity::AddSystemBit(bitset<BITSIZE> bit)
	{
		m_systemBits |= bit;
	}

	void Entity::AddTypeBit(bitset<BITSIZE> bit)
	{
		m_typeBits |= bit;
	}

	Component* Entity::GetComponent(ComponentType & type)
	{
		return m_pEntityManager->GetComponent(this, type);
	}

	ImmutableBag<Component*> & Entity::GetComponents()
	{
		return m_pEntityManager->GetComponents(this);
	}

	int Entity::GetId()
	{
		return m_id;
	}

	bitset<BITSIZE> Entity::GetSystemBits()
	{
		return m_systemBits;
	}

	bitset<BITSIZE> Entity::GetTypeBits()
	{
		return m_typeBits;
	}

	long int Entity::GetUniqueId()
	{
		return m_uniqueId;
	}

	bool Entity::IsActive()
	{
		return m_pEntityManager->IsActive(GetId());
	}

	void Entity::Refresh()
	{
		m_pWorld->RefreshEntity(this);
	}

	Component* Entity::AddComponent(Component * c)
	{
		m_pEntityManager->AddComponent(this, c);
		c->Init();
		return c;
	}

	void Entity::RemoveComponent(ComponentType & type)
	{
		m_pEntityManager->RemoveComponent(this, type);
	}

	void Entity::RemoveSystemBit(bitset<BITSIZE> bit)
	{
		m_systemBits &= ~bit;
	}

	void Entity::RemoveTypeBit(bitset<BITSIZE> bit)
	{
		m_typeBits &= ~bit;
	}

	void Entity::Reset()
	{
		m_typeBits = 0;
		m_systemBits = 0;
	}

	void Entity::SetGroup(string group)
	{
		m_pWorld->GetGroupManager()->Set(group, this);
	}

	void Entity::SetSystemBits(bitset<BITSIZE> systemBits)
	{
		m_systemBits = systemBits;
	}

	void Entity::SetTag(string tag)
	{
		m_pWorld->GetTagManager()->Subscribe(tag, this);
	}

	void Entity::SetTypeBits(bitset<BITSIZE> typeBits)
	{
		m_typeBits = typeBits;
	}

	void Entity::SetUniqueId(long int uniqueId)
	{
		m_uniqueId = uniqueId;
	}

	std::string Entity::ToString()
	{
		std::ostringstream oss;
		oss << "Entity[" << m_id << "]\n";
		return  oss.str();
	}

	void Entity::Remove()
	{
		m_pWorld->DeleteEntity(this);
	}
};
