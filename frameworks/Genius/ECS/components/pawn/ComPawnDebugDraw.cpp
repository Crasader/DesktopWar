
#include "ComPawnDebugDraw.h"
#include "ECS/components/common/ComBoxCollider.h"
#include "ECS/components/common/ComRenderRoot.h"
#include "ECS/components/pawn/ComPawnAgent.h"
#include "data/auto/Role_cfg.hpp"
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
	//
	ComPawnAgent* tempCom = this->GetEntity()->GetComponent<ComPawnAgent>();
	do
	{
		// attack range
		Vec2 center(0, 0);// posCom->x, posCom->y);
		float radiusView = tempCom->m_roleCfg->viewRange;
		float radiusNear = tempCom->m_roleCfg->fightRangeNear;
		float radiusFar = tempCom->m_roleCfg->fightRangeFar;
		this->Clear();
		this->pNodeNearRange->drawRect(Vec2(-radiusView*0.5f, -radiusView*0.25f), Vec2(radiusView*0.5f, radiusView*0.25f), Color4F::RED);
		this->pNodeNearRange->drawRect(Vec2(-radiusNear*0.5f, -radiusNear*0.25f), Vec2(radiusNear*0.5f, radiusNear*0.25f), Color4F::RED);
		this->pNodeNearRange->drawRect(Vec2(-radiusFar*0.5f, -radiusFar*0.25f), Vec2(radiusFar*0.5f, radiusFar*0.25f), Color4F::RED);
		//debugCom->pNodeNearRange->drawCircle(center, radiusNear, 0, 12, true, Color4F::RED);
		//debugCom->pNodeFarRange->drawCircle(center, radiusFar, 0, 12, true, Color4F::RED);
	} while (false);

	/*do
	{
		// box collider
		ComBoxCollider* ComBoxCollider = GetEntity()->GetComponent<ComBoxCollider>();
		Vec2 center(ComBoxCollider->centerX, ComBoxCollider->centerY);
		Vec2 origin(center.x - ComBoxCollider->width*0.5f, center.y + ComBoxCollider->height*0.5f);
		Vec2 destination(center.x + ComBoxCollider->width*0.5f, center.y - ComBoxCollider->height*0.5f);
		this->pNodeBoxCollider->drawRect(origin, destination, Color4F::GREEN);
	} while (false);*/
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