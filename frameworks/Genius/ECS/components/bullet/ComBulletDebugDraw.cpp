
#include "ComBulletDebugDraw.h"
#include "gfx/gfx.h"

using namespace Genius;

COM_CREATE_FN_IMPL(ComBulletDebugDraw);

ComBulletDebugDraw::ComBulletDebugDraw()
{
	pRoot = Node::create();
	pNodeBoxCollider = DrawNode::create();
	pNodeHurtRange = DrawNode::create();
	pRoot->addChild(pNodeBoxCollider);
	pRoot->addChild(pNodeHurtRange);
	SceneManager::GetSingleton()->AddToMapLayer(pRoot);
}

ComBulletDebugDraw::~ComBulletDebugDraw()
{
	pRoot->removeFromParent();
}

void ComBulletDebugDraw::Clear()
{
	pNodeBoxCollider->clear();
	pNodeHurtRange->clear();
}