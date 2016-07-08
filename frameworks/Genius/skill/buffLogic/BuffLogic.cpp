
#include "BuffLogic.h"
#include "common//Log.h"

#include "BL_ChangeAttr.h"

using namespace Genius;


std::map<int, BuffLogic*> BuffLogic::sLogicMap;
std::map<int, BuffLogicCreatorFunc> BuffLogic::sLogicCreator;

void BuffLogic::RegisterCreator(int type, BuffLogicCreatorFunc func)
{
	if (nullptr == func)
		return;

	if (type <= LogicType::Unknown || type >= LogicType::Count)
	{
		Log::Error("BuffLogic::RegisterCreator, wrong logic type : %d", type);
		return;
	}

	if (sLogicCreator.find(type) == sLogicCreator.end())
	{
		sLogicCreator.insert(std::make_pair(type, func));
	}
	else
	{
		Log::Error("BuffLogic::RegisterCreator, register logic creator, repeated ! id : %d", type);
	}
}

BuffLogic* BuffLogic::GetLogic(int type)
{
	if (sLogicCreator.size() == 0)
	{
		REGISTER_BUFFLOGIC_CREATOR(LogicType::ChangeAttr, BL_ChangeAttr);
		//REGISTER_BUFFLOGIC_CREATOR(LogicType::ChangeAttr, BL_ChangeAttr);
	}

	if (type <= LogicType::Unknown || type >= LogicType::Count)
	{
		Log::Error("wrong logic type : %d", type);
		return nullptr;
	}
	BuffLogic* logic = nullptr;

	if (sLogicMap.find(type) != sLogicMap.end())
	{
		logic = sLogicMap[type];
	}
	else
	{
		logic = (BuffLogic*)(*sLogicCreator[type])();
		sLogicMap.insert(std::make_pair(type, logic));
	}

	return logic;
}









