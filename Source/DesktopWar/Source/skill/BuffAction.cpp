// d:)
#include "BuffAction.h"
#include "BuffActionDataMgr.h"
#include "UserActions.h"

using namespace Genius;

/************************************************************************/
/*                                          BuffAction                            */
/************************************************************************/

void BuffAction::SetTemplate(BuffActionData* data)
{
	if (nullptr == data)
		return;

	m_templateData = data;

	BuffParam actionParam;
	actionParam.buffIndex = data->id;
	actionParam.buffType = data->buffType;
	for (int i = 0; i < MaxActionParamNum; ++i)
		actionParam.params[i] = data->params[i];
	actionParam.paramStr;

	m_action.param = actionParam;

	m_action.pFunc = FindFunc(data->action);
}

bool BuffAction::IsConditionRight(BuffEnvParam&)
{
	return true;
}

int BuffAction::operator()(BuffEnvParam& env)
{
	if (m_action.pFunc)
	{
		return m_action.pFunc(env, m_action.param);
	}
	else
		return 0;
}

BuffActionFunction BuffAction::FindFunc(std::string& name)
{
	return UserActions::FindAction(name);
}