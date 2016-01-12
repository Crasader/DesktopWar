// d:)
#include "PawnDebugDrawCom.h"


using namespace Genius;


PawnDebugDrawCom::PawnDebugDrawCom()
{
	pRoot = Node::create();
	pNodeBoxCollider = DrawNode::create();
	pNodeNearRange = DrawNode::create();
	pNodeFarRange = DrawNode::create();
	pRoot->addChild(pNodeBoxCollider);
	pRoot->addChild(pNodeNearRange);
	pRoot->addChild(pNodeFarRange);
	SceneManager::GetInstance().AddToMapLayer(pRoot);
}

PawnDebugDrawCom::~PawnDebugDrawCom()
{
	pRoot->removeFromParent();
}

void PawnDebugDrawCom::Clear()
{
	pNodeBoxCollider->clear();
	pNodeNearRange->clear();
	pNodeFarRange->clear();
}