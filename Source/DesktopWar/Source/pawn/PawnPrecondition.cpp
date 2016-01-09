// d:)
#include "PawnPrecondition.h"
#include "ECS/ECSHeaders.h"
#include "ECS/Entity.h"
#include "ECS/components/BevtreeCom.h"
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
	PawnAttributeCom*attCom = data.pEntity->GetComponent<PawnAttributeCom>();
	if (attCom)
		return attCom->curLife > 0;

	return true;
}

bool LowHP::Check(BHUpdateContext& context)
{
	EntityBevInputData& data = context.GetRealDataType<EntityBevInputData>();
	PawnAttributeCom* attCom = data.pEntity->GetComponent<PawnAttributeCom>();
	PawnTemplateCom* tempCom = data.pEntity->GetComponent<PawnTemplateCom>();
	if (attCom && tempCom)
		return attCom->curLife < value * tempCom->pRoleData->baseLife;

	return true;
}

bool HighHP::Check(BHUpdateContext& context)
{
	EntityBevInputData& data = context.GetRealDataType<EntityBevInputData>();
	PawnAttributeCom*attCom = data.pEntity->GetComponent<PawnAttributeCom>();
	PawnTemplateCom* tempCom = data.pEntity->GetComponent<PawnTemplateCom>();
	if (attCom && tempCom)
		return attCom->curLife >= value * tempCom->pRoleData->baseLife;

	return true;
}

bool HaveTarget::Check(BHUpdateContext& context)
{
	EntityBevInputData& data = context.GetRealDataType<EntityBevInputData>();
	PawnFightCom* fightCom = data.pEntity->GetComponent<PawnFightCom>();
	if (fightCom)
		return fightCom->haveTarget;

	return false;
}

bool ReachTarget::Check(BHUpdateContext& context)
{
	EntityBevInputData& data = context.GetRealDataType<EntityBevInputData>();
	PawnFightCom* fightCom = data.pEntity->GetComponent<PawnFightCom>();
	if (fightCom)
		return fightCom->haveTarget && fightCom->isTargetInNearRange;

	return false;
}

bool TargetInNearRange::Check(BHUpdateContext& context)
{
	EntityBevInputData& data = context.GetRealDataType<EntityBevInputData>();
	PawnFightCom* fightCom = data.pEntity->GetComponent<PawnFightCom>();
	if (fightCom)
		return fightCom->haveTarget && fightCom->isTargetInNearRange;

	return false;
}

bool TargetInFarRange::Check(BHUpdateContext& context)
{
	EntityBevInputData& data = context.GetRealDataType<EntityBevInputData>();
	PawnFightCom* fightCom = data.pEntity->GetComponent<PawnFightCom>();
	if (fightCom)
		return fightCom->haveTarget && fightCom->isTargetInFarRange && ! fightCom->isTargetInNearRange;

	return false;
}