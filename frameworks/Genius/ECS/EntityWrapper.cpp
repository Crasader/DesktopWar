
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


Genius::IComponent* EntityWrapper::AddComponent(const char* name)
{
	Genius::IComponent* com = nullptr;
	string comName = name;
	if (comName == "ComTransform")
		com = new ComTransform();
	else if (comName == "ComBoxCollider")
		com = new ComBoxCollider();
	else if (comName == "ComColliderHandler")
		com = new ComColliderHandler();
	else if (comName == "ComAnimation")
		com = new ComAnimation();
	else if (comName == "ComTeam")
		com = new ComTeam();
	else if (comName == "ComTarget")
		com = new ComTarget();
	else if (comName == "ComParticle")
		com = new ComParticle();
	else if (comName == "ComBezierMovement")
		com = new ComBezierMovement();
	else if (comName == "ComDelayTrackMovement")
		com = new ComDelayTrackMoving();
	else if (comName == "ComPawnAgent")
		com = new ComPawnAgent();
	else if (comName == "ComPawnAnim")
		com = new ComPawnAnim();
	else if (comName == "ComPawnDebugDraw")
		com = new ComPawnDebugDraw();
	else if (comName == "ComPawnDirection")
		com = new ComPawnDirection();
	else if (comName == "ComPawnFight")
		com = new ComPawnFight();
	else if (comName == "ComPawnNavigation")
		com = new ComPawnNavigation();
	else if (comName == "ComPawnBevtree")
		com = new ComPawnBevtree();

	else if (comName == "ComBulletAgent")
		com = new ComBulletAgent();
	else if (comName == "ComBulletAnimArrow")
		com = new ComBulletAnimArrow();
	else if (comName == "ComBulletAnimBase")
		com = new ComBulletAnimBase();
	else if (comName == "ComBulletAnimBomb")
		com = new ComBulletAnimBomb();
	else if (comName == "ComBulletDamageNone")
		com = new ComBulletDamageNone();
	else if (comName == "ComBulletDamageScope")
		com = new ComBulletDamageScope();
	else if (comName == "ComBulletDamageSingle")
		com = new ComBulletDamageSingle();
	else if (comName == "ComBulletDebugDraw")
		com = new ComBulletDebugDraw();
	else if (comName == "ComBulletAnimEgg")
		com = new ComBulletAnimEgg();

	m_entity->AddComponent(com);
	m_entity->Refresh();

	return com;
}




