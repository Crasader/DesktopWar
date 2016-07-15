
#include "ComPawnDebugDraw.h"

USING_NS_CC;
using namespace Genius;


COM_CREATE_FN_IMPL(ComPawnDebugDraw);

void ComPawnDebugDraw::Create()
{
	pRoot = Node::create();
	pNodeBoxCollider = DrawNode::create();
	pNodeNearRange = DrawNode::create();
	pNodeFarRange = DrawNode::create();
	pRoot->addChild(pNodeBoxCollider);
	pRoot->addChild(pNodeNearRange);
	pRoot->addChild(pNodeFarRange);
	SceneManager::GetSingleton()->AddToMapLayer(pRoot);
}

ComPawnDebugDraw::~ComPawnDebugDraw()
{
	pRoot->removeFromParent();
}

void ComPawnDebugDraw::Clear()
{
	pNodeBoxCollider->clear();
	pNodeNearRange->clear();
	pNodeFarRange->clear();
}