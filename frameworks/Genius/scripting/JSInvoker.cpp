

#include "JSInvoker.h"
#include <string>
#include "scripting/js-bindings/manual/ScriptingCore.h"


void JSInvoker::Invoke_Update(float timePassed)
{
	char jsCallString[64];
	sprintf_s(jsCallString, "Game.OnUpdate(%f);", timePassed);
	ScriptingCore::getInstance()->evalString(jsCallString);
}

void JSInvoker::Invoke_LongUpdate(float timePassed)
{
	char jsCallString[64];
	sprintf_s(jsCallString, "Game.OnLongUpdate(%f);", timePassed);
	ScriptingCore::getInstance()->evalString(jsCallString);
}

void JSInvoker::Invoke_ArmatureFrameEvent(int entityID, const char* eventName)
{
	char jsCallString[64];
	sprintf_s(jsCallString, "Game.OnArmatureFrameEvent(%d, '%s');", entityID, eventName);
	ScriptingCore::getInstance()->evalString(jsCallString);
}

void JSInvoker::Invoke_ArmatureMovementEvent(int entityID, int movement, const char* animName)
{
	char jsCallString[64];
	sprintf_s(jsCallString, "Game.OnArmatureMovementEvent(%d, %d, '%s');", entityID, movement, animName);
	ScriptingCore::getInstance()->evalString(jsCallString);
}

void JSInvoker::Invoke_ModifyEntityAttr(int entityID, int calType, int attrType, int value, int atkType)
{
	char jsCallString[64];
	sprintf_s(jsCallString, "Game.OnModifyEntityAttr(%d, %d, %d, %d, %d);", entityID, calType, attrType, value, atkType);
	ScriptingCore::getInstance()->evalString(jsCallString);
}
