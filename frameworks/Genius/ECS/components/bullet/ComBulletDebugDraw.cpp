
#include "ComBulletDebugDraw.h"
#include "ECS/components/common/ComBoxCollider.h"
#include "ECS/components/common/ComRenderRoot.h"
#include "ECS/components/pawn/ComPawnAgent.h"
#include "data/auto/Bullet_cfg.hpp"
#include "gfx/gfx.h"
#include "Log.h"

using namespace Genius;

COM_CREATE_FN_IMPL(ComBulletDebugDraw);

void ComBulletDebugDraw::OnAwake()
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

	Refresh();
}

ComBulletDebugDraw::~ComBulletDebugDraw()
{
	
}

void ComBulletDebugDraw::Refresh()
{
	Clear();
	
	auto agent = GetEntity()->GetComponent<ComPawnAgent>();
	auto collider = GetEntity()->GetComponent<ComBoxCollider>();
	if (nullptr != agent && nullptr != collider)
	{
		// attack range
		Vec2 center1(0, 0);
		float radiusNear = agent->pBulletData->buffTargetRadius;
		this->pNodeHurtRange->drawCircle(center1, radiusNear, 0, 12, true, Color4F::RED);

		// box collider
		Vec2 center2(collider->centerX, collider->centerY);
		Vec2 origin2(center2.x - collider->width*0.5f, center2.y + collider->height*0.5f);
		Vec2 dest2(center2.x + collider->width*0.5f, center2.y - collider->height*0.5f);
		this->pNodeBoxCollider->drawRect(origin2, dest2, Color4F::GREEN);
	}
}

void ComBulletDebugDraw::Clear()
{
	pNodeBoxCollider->clear();
	pNodeHurtRange->clear();
}