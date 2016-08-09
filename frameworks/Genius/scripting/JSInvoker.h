

#pragma once

class JSInvoker
{
public:

	static void Invoke_Update(float time);

	static void Invoke_LongUpdate(float time);

	static void Invoke_ArmatureFrameEvent(int entityID, const char* eventName);

	static void Invoke_ArmatureMovementEvent(int entityID, int movement, const char* animName);

};