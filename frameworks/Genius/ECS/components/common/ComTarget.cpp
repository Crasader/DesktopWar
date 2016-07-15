
#include "ComTarget.h"

using namespace Genius;

COM_CREATE_FN_IMPL(ComTarget);

void ComTarget::Create(int _type, int _id/* = Entity::InvalidID*/, float _x/* = 0*/, float _y/* = 0*/)
{
	targetType = _type;
	targetID = _id;
	targetX = _x;
	targetY = _y;
}