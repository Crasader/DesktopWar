// d:)
#include "PawnPrecondition.h"
#include "ECS/ecs.h"
#include "ECS/core/Entity.h"
#include "ECS/components/pawn/ComPawnBevtree.h"
#include "data/RoleDataMgr.h"
#include "Common/RandUtility.h"
#include "Logger.h"

bool Probablity::Check(BHUpdateContext& context)
{
	if (!checked)
	{
		randomValue = RandUtility::RandProbablity();
		checked = true;
	}
	return randomValue < value;
}

void Probablity::Reset()
{
	randomValue = 0;
	checked = false;
}

bool HaveHP::Check(BHUpdateContext& context)
{
	EntityBevInputData& data = context.GetRealDataType<EntityBevInputData>();
	ComPawnAttribute*attCom = data.pEntity->GetComponent<ComPawnAttribute>();
	if (attCom)
		return attCom->curLife > 0;

	return true;
}

bool LowHP::Check(BHUpdateContext& context)
{
	EntityBevInputData& data = context.GetRealDataType<EntityBevInputData>();
	ComPawnAttribute* attCom = data.pEntity->GetComponent<ComPawnAttribute>();
	ComPawnAgent* tempCom = data.pEntity->GetComponent<ComPawnAgent>();
	if (attCom && tempCom)
		return attCom->curLife < value * tempCom->pRoleData->baseLife;

	return true;
}

bool HighHP::Check(BHUpdateContext& context)
{
	EntityBevInputData& data = context.GetRealDataType<EntityBevInputData>();
	ComPawnAttribute*attCom = data.pEntity->GetComponent<ComPawnAttribute>();
	ComPawnAgent* tempCom = data.pEntity->GetComponent<ComPawnAgent>();
	if (attCom && tempCom)
		return attCom->curLife >= value * tempCom->pRoleData->baseLife;

	return true;
}

bool HaveTarget::Check(BHUpdateContext& context)
{
	EntityBevInputData& data = context.GetRealDataType<EntityBevInputData>();
	ComPawnFight* fightCom = data.pEntity->GetComponent<ComPawnFight>();
	if (fightCom)
		return fightCom->haveTarget;

	return false;
}

bool ReachTarget::Check(BHUpdateContext& context)
{
	EntityBevInputData& data = context.GetRealDataType<EntityBevInputData>();
	ComPawnFight* fightCom = data.pEntity->GetComponent<ComPawnFight>();
	if (fightCom)
		return fightCom->haveTarget && fightCom->isTargetInNearRange;

	return false;
}

bool TargetInNearRange::Check(BHUpdateContext& context)
{
	EntityBevInputData& data = context.GetRealDataType<EntityBevInputData>();
	ComPawnFight* fightCom = data.pEntity->GetComponent<ComPawnFight>();
	if (fightCom)
		return fightCom->haveTarget && fightCom->isTargetInNearRange;

	return false;
}

bool TargetInFarRange::Check(BHUpdateContext& context)
{
	EntityBevInputData& data = context.GetRealDataType<EntityBevInputData>();
	ComPawnFight* fightCom = data.pEntity->GetComponent<ComPawnFight>();
	if (fightCom)
		return fightCom->haveTarget && fightCom->isTargetInFarRange && ! fightCom->isTargetInNearRange;

	return false;
}