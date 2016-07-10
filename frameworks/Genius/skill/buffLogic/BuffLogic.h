
#pragma once

#include <map>

#define DECLARE_BUFFLOGIC_CREATOR(class_name)\
	static void* Create##class_name();

#define IMPL_BUFFLOGIC_CREATOR(class_name)\
	void* class_name::Create##class_name()\
	{return new class_name(); }

#define REGISTER_BUFFLOGIC_CREATOR(id, class_name)\
	BuffLogic::RegisterCreator(id, class_name::Create##class_name);

typedef void* (*BuffLogicCreatorFunc)(void);


namespace Genius
{
	class  Buff;

	class BuffLogic
	{
	public:
		virtual ~BuffLogic(){};
		virtual void OnActive(Buff* buff) = 0;
		virtual void OnDeactive(Buff* buff) = 0;
		virtual void OnEffect(Buff* buff) = 0;

	public:
		enum LogicType
		{
			Unknown			= 0,
			ChangeAttr		= 1,		// 该属性
			Damage			= 2,		// 伤害（来自npc 或 子弹）
			Spawn				= 3,		// 召唤、出生npc

			Count,
		};

		static std::map<int, BuffLogic*> sLogicMap;
		static std::map<int, BuffLogicCreatorFunc> sLogicCreator;

		static BuffLogic* GetLogic(int type);
		static void RegisterCreator(int type, BuffLogicCreatorFunc func);
	};

};