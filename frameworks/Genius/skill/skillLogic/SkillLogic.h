
#pragma once

#include <map>

#define DECLARE_SKILLLOGIC_CREATOR(class_name)\
	static void* Create##class_name();

#define IMPL_SKILLLOGIC_CREATOR(class_name)\
	void* class_name::Create##class_name()\
	{return new class_name(); }

#define REGISTER_SKILLLOGIC_CREATOR(id, class_name)\
	SkillLogic::RegisterCreator(id, class_name::Create##class_name);

typedef void* (*SkillLogicCreatorFunc)(void);


namespace Genius
{
	class Skill;

	class SkillLogic
	{
	public:
		virtual ~SkillLogic(){};
		virtual void OnActive(Skill* skill) = 0;
		virtual void OnDeactive(Skill* skill) = 0;

	public:
		enum LogicType
		{
			Unknown = 0,
			Buff = 1,
			Bullet = 2,

			Count,
		};

		static std::map<int, SkillLogic*> sLogicMap;
		static std::map<int, SkillLogicCreatorFunc> sLogicCreator;

		static SkillLogic* GetLogic(int type);
		static void RegisterCreator(int type, SkillLogicCreatorFunc func);
	};

};