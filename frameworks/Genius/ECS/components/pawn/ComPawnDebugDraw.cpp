
#include "ComPawnDebugDraw.h"
#include "ecs/components/common/ComRenderRoot.h"
#include "Log.h"


USING_NS_CC;
using namespace Genius;


COM_CREATE_FN_IMPL(ComPawnDebugDraw);

void ComPawnDebugDraw::Create()
{
	auto render = GetEntity()->GetComponent<ComRenderRoot>();
	if (nullptr == render)
	{
		Log::Error("ComPawnAnim.create : ComRenderRoot required .");
		return;
	}

	pRoot = Node::create();
	pNodeBoxCollider = DrawNode::create();
	pNodeNearRange = DrawNode::create();
	pNodeFarRange = DrawNode::create();
	pRoot->addChild(pNodeBoxCollider);
	pRoot->addChild(pNodeNearRange);
	pRoot->addChild(pNodeFarRange);
	render->AddChild(pRoot);
}

ComPawnDebugDraw::~ComPawnDebugDraw()
{
	
}

void ComPawnDebugDraw::Clear()
{
	pNodeBoxCollider->clear();
	pNodeNearRange->clear();
	pNodeFarRange->clear();
}