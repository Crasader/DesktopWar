
#include "EntityWrapper.h"
#include "ECS/ecs.h"
#include "common/Log.h"
#include <string>
#include <unordered_map>

using namespace std;
using namespace Genius;


typedef IComponent* (*CreateComFunc)(void);

static unordered_map<std::string, CreateComFunc> sCreateComFuncs;

#define REG_CREATE_COM(classname)\
	sCreateComFuncs[#classname] = classname::create_inst;




static void _lazyInitComFuncs()
{
	if (sCreateComFuncs.size() != 0)
		return;
	REG_CREATE_COM(ComTransform);
	REG_CREATE_COM(ComBoxCollider);
	REG_CREATE_COM(ComColliderHandler);
	REG_CREATE_COM(ComRenderRoot);
	REG_CREATE_COM(ComParticle);
	REG_CREATE_COM(ComBezierMovement);
	REG_CREATE_COM(ComDelayTrackMoving);

	REG_CREATE_COM(ComPawnAgent);
	REG_CREATE_COM(ComPawnAnim);
	REG_CREATE_COM(ComPawnDebugDraw);
	REG_CREATE_COM(ComPawnFight);
	REG_CREATE_COM(ComPawnNavigation);
	REG_CREATE_COM(ComPawnBevtree);


	REG_CREATE_COM(ComBulletAnimArrow);
	REG_CREATE_COM(ComBulletAnimBase);
	REG_CREATE_COM(ComBulletAnimBomb);
	REG_CREATE_COM(ComBulletDamageNone);
	REG_CREATE_COM(ComBulletDamageScope);
	REG_CREATE_COM(ComBulletDamageSingle);
	REG_CREATE_COM(ComBulletDebugDraw);
	REG_CREATE_COM(ComBulletAnimEgg);
}


EntityWrapper::EntityWrapper(Entity* ent)
{
	m_entity = ent;
}

EntityWrapper::~EntityWrapper()
{

}

int EntityWrapper::GetID()
{
	return m_entity->GetId();
}


Genius::IComponent* EntityWrapper::AddComponent(const char* name)
{
	_lazyInitComFuncs();

	Genius::IComponent* com = nullptr;
	string comName = name;
	auto iter = sCreateComFuncs.find(comName);
	if (iter != sCreateComFuncs.end())
	{
		com = (*iter->second)();
	}

	if (com != nullptr)
		m_entity->AddComponent(com);
	else
		Log::Error("com not exist : %s", name);

	return com;
}


void EntityWrapper::AddTag(const char* tag)
{
	ECSWorld::GetSingleton()->AddTag(this->m_entity, tag);
}


void EntityWrapper::RemoveTag(const char* tag)
{
	ECSWorld::GetSingleton()->RemoveTag(this->m_entity, tag);
}


