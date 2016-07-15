
#include "ComColliderHandler.h"

using namespace Genius;

COM_CREATE_FN_IMPL(ComColliderHandler);

void ComColliderHandler::Create(std::function<void(int, int)> _enterFunc, std::function<void(int, int)> _exitFunc)
{
	_enterColliderListener = _enterFunc;
	_exitColliderListener = _exitFunc;
}

