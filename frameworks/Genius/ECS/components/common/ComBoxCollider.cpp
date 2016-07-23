
#include "ComBoxCollider.h"
#include "ECS/core/ECSWorld.h"
#include "app/GameDefine.h"

using namespace Genius;

COM_CREATE_FN_IMPL(ComBoxCollider);


void ComBoxCollider::OnAwake()
{
	ECSWorld::GetSingleton()->AddTag(this->GetEntity(), GameDefine::Tag_BoxCollider);
}

void ComBoxCollider::Create(bool _static, float _centerX, float _centerY, float _width, float _height)
{
	isStatic = _static;
	centerX = _centerX;
	centerY = _centerY;
	width = _width;
	height = _height;
	areaID = 0;
}

