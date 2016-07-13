
#include "ComColliderHandler.h"

using namespace Genius;

void ComColliderHandler::Create(std::function<void(int, int)> _enterFunc, std::function<void(int, int)> _exitFunc)
{
	_enterColliderListener = _enterFunc;
	_exitColliderListener = _exitFunc;
}

