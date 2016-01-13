// d:)
#include "BulletDebugDrawCom.h"
#include "gfx/gfx.h"

using namespace Genius;

BulletDebugDrawCom::BulletDebugDrawCom()
{
	pRoot = Node::create();
	pNodeBoxCollider = DrawNode::create();
	pNodeHurtRange = DrawNode::create();
	pRoot->addChild(pNodeBoxCollider);
	pRoot->addChild(pNodeHurtRange);
	SceneManager::GetInstance().AddToMapLayer(pRoot);
}

BulletDebugDrawCom::~BulletDebugDrawCom()
{
	pRoot->removeFromParent();
}

void BulletDebugDrawCom::Clear()
{
	pNodeBoxCollider->clear();
	pNodeHurtRange->clear();
}