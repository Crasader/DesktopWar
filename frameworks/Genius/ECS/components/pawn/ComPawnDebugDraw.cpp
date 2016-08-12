
#include "ComPawnDebugDraw.h"
#include "ECS/components/common/ComBoxCollider.h"
#include "ECS/components/common/ComRenderRoot.h"
#include "ECS/components/pawn/ComPawnAgent.h"
#include "data/auto/Role_cfg.hpp"
#include "Log.h"


USING_NS_CC;
using namespace Genius;


COM_CREATE_FN_IMPL(ComPawnDebugDraw);

void ComPawnDebugDraw::OnAwake()
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
	pNodeViewRange = DrawNode::create();
	pRoot->addChild(pNodeBoxCollider);
	pRoot->addChild(pNodeNearRange);
	pRoot->addChild(pNodeFarRange);
	pRoot->addChild(pNodeViewRange);
	render->AddChild(pRoot);
	
	Refresh();
}

ComPawnDebugDraw::~ComPawnDebugDraw()
{
	
}

void ComPawnDebugDraw::Refresh()
{
	Clear();
	
	auto agent = this->GetEntity()->GetComponent<ComPawnAgent>();
	if (agent != nullptr)
	{
		float radiusView = agent->m_roleCfg->viewRange;
		float radiusNear = agent->m_roleCfg->fightRangeNear;
		float radiusFar = agent->m_roleCfg->fightRangeFar;
		this->pNodeViewRange->drawRect(Vec2(-radiusView*0.5f, -radiusView*0.25f), Vec2(radiusView*0.5f, radiusView*0.25f), Color4F::WHITE);
		this->pNodeNearRange->drawRect(Vec2(-radiusNear*0.5f, -radiusNear*0.25f), Vec2(radiusNear*0.5f, radiusNear*0.25f), Color4F::RED);
		this->pNodeFarRange->drawRect(Vec2(-radiusFar*0.5f, -radiusFar*0.25f), Vec2(radiusFar*0.5f, radiusFar*0.25f), Color4F::ORANGE);
	}

	// collider
	auto collider = GetEntity()->GetComponent<ComBoxCollider>();
	if (collider != nullptr)
	{
		Vec2 center(collider->centerX, collider->centerY);
		Vec2 origin(center.x - collider->width*0.5f, center.y + collider->height*0.5f);
		Vec2 destination(center.x + collider->width*0.5f, center.y - collider->height*0.5f);
		this->pNodeBoxCollider->drawRect(origin, destination, Color4F::GREEN);
	}

}

void ComPawnDebugDraw::Clear()
{
	pNodeBoxCollider->clear();
	pNodeNearRange->clear();
	pNodeFarRange->clear();
	pNodeViewRange->clear();
}