
#include "SkillLogic.h"
#include "common/Log.h"

#include "SL_Buff.h"
#include "SL_Bullet.h"


using namespace Genius;


std::map<int, SkillLogic*> SkillLogic::sLogicMap;
std::map<int, SkillLogicCreatorFunc> SkillLogic::sLogicCreator;

void SkillLogic::RegisterCreator(int type, SkillLogicCreatorFunc func)
{
	if (nullptr == func)
		return;

	if (type <= LogicType::Unknown || type >= LogicType::Count)
	{
		Log::Error("SkillLogic::RegisterCreator, wrong logic type : %d", type);
		return;
	}

	if (sLogicCreator.find(type) == sLogicCreator.end())
	{
		sLogicCreator.insert(std::make_pair(type, func));
	}
	else
	{
		Log::Error("SkillLogic::RegisterCreator, register logic creator, repeated ! id : %d", type);
	}
}

SkillLogic* SkillLogic::GetLogic(int type)
{
	if (sLogicCreator.size() == 0)
	{
		REGISTER_SKILLLOGIC_CREATOR(LogicType::Buff, SL_Buff);
		REGISTER_SKILLLOGIC_CREATOR(LogicType::Bullet, SL_Bullet);
	}

	if (type <= LogicType::Unknown || type >= LogicType::Count)
	{
		Log::Error("wrong logic type : %d", type);
		return nullptr;
	}
	SkillLogic* logic = nullptr;

	if (sLogicMap.find(type) != sLogicMap.end())
	{
		logic = sLogicMap[type];
	}
	else
	{
		logic = (SkillLogic*)(*sLogicCreator[type])();
		sLogicMap.insert(std::make_pair(type, logic));
	}

	return logic;
}









