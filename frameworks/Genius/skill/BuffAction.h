#ifndef _GENIUS_BUFFACTION_H_
#define _GENIUS_BUFFACTION_H_

#include <string>

#define MaxParamNum 5

namespace Genius
{
	class Buff;

	struct BuffEnvParam
	{
		Buff*		buff;
		int			skillID;
		bool			apply;
	};

	struct BuffParam
	{
		int	buffType;
		int	buffIndex;
		int	params[MaxParamNum];
		char	paramStr[128];
	};

	typedef int(*BuffActionFunction)(BuffEnvParam&, BuffParam&);

	struct BuffActionFucMap
	{
		std::string name;
		BuffActionFunction func;
	};

	class BuffActionData;
	class BuffAction
	{
		struct _Function
		{
			BuffActionFunction	pFunc;
			BuffParam				param;
		};

	public:
		void SetTemplate(BuffActionData* data);
		bool IsConditionRight(BuffEnvParam&);
		int operator()(BuffEnvParam&);
		BuffActionFunction FindFunc(std::string& name);

	private:
		int ParseAction(std::string name,  BuffParam param);
		int ParseCondition();

	private:
		BuffActionData*		m_templateData;
		_Function					m_action;
		_Function					m_condition;
	};

}

#endif