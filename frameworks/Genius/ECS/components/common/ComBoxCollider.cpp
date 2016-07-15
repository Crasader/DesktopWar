
#include "ComBoxCollider.h"

using namespace Genius;

COM_CREATE_FN_IMPL(ComBoxCollider);

void ComBoxCollider::Create(bool _positive, float _centerX, float _centerY, float _width, float _height)
{
	positive = _positive;
	centerX = _centerX;
	centerY = _centerY;
	width = _width;
	height = _height;
	areaID = 0;
	for (int i = 0; i < MaxCount; ++i)
		collideIDs[i] = Entity::InvalidID;
}

