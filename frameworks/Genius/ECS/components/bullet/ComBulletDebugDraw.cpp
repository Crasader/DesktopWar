
#include "ComBulletDebugDraw.h"
#include "ecs/components/common/ComRenderRoot.h"
#include "gfx/gfx.h"
#include "Log.h"

using namespace Genius;

COM_CREATE_FN_IMPL(ComBulletDebugDraw);

ComBulletDebugDraw::ComBulletDebugDraw()
{
	auto render = GetEntity()->GetComponent<ComRenderRoot>();
	if (nullptr == render)
	{
		Log::Error("ComPawnAnim.create : ComRenderRoot required .");
		return;
	}

	pRoot = Node::create();
	pNodeBoxCollider = DrawNode::create();
	pNodeHurtRange = DrawNode::create();
	pRoot->addChild(pNodeBoxCollider);
	pRoot->addChild(pNodeHurtRange);
	render->AddChild(pRoot);
}

ComBulletDebugDraw::~ComBulletDebugDraw()
{
	
}

void ComBulletDebugDraw::Clear()
{
	pNodeBoxCollider->clear();
	pNodeHurtRange->clear();
}