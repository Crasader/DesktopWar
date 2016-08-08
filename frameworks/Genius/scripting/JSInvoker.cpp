

#include "JSInvoker.h"
#include <string>
#include "scripting/js-bindings/manual/ScriptingCore.h"


void JSInvoker::Invoke_Update(float timePassed)
{
	char jsCallString[32];
	sprintf_s(jsCallString, "Game.OnUpdate(%f);", timePassed);
	ScriptingCore::getInstance()->evalString(jsCallString);
}

void JSInvoker::Invoke_LongUpdate(float timePassed)
{
	char jsCallString[32];
	sprintf_s(jsCallString, "Game.OnLongUpdate(%f);", timePassed);
	ScriptingCore::getInstance()->evalString(jsCallString);
}

