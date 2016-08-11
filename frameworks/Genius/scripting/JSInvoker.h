

#pragma once

class JSInvoker
{
public:

	static void Invoke_Update(float time);

	static void Invoke_LongUpdate(float time);

	static void Invoke_ArmatureFrameEvent(int entityID, const char* eventName);

	static void Invoke_ArmatureMovementEvent(int entityID, int movement, const char* animName);

	static void Invoke_ModifyEntityAttr(int entityID, int calType, int attrType, int value, int atkType=-1);

	static void Invoke_PushEvent(int entityID, const char* eventName);

};