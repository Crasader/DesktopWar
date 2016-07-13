
#include "EntityWrapper.h"
#include "ECS/ecs.h"


using namespace Genius;


EntityWrapper::EntityWrapper(Entity* ent)
{
	m_entity = ent;
}

int EntityWrapper::GetID()
{
	return m_entity->GetId();
}


Genius::Component* EntityWrapper::AddComponent(const char* name)
{
	Genius::Component* com = nullptr;
	string comName = name;
	if (comName == "ComPosition")
		com = new ComPosition();

	return com;
}




