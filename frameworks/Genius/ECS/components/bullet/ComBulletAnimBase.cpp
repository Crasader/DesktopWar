
#include "ComBulletAnimBase.h"
#include "ecs/components/common/ComRenderRoot.h"
#include "gfx/gfx.h"
#include "common/Log.h"

using namespace Genius;

COM_CREATE_FN_IMPL(ComBulletAnimBase);

void ComBulletAnimBase::Create(const std::string& bodyFileName)
{
	m_pAvatarRoot = nullptr;
	m_pBodyArmature = nullptr;

	auto render = GetEntity()->GetComponent<ComRenderRoot>();
	if (nullptr == render)
	{
		Log::Error("ComBulletAnimBase.create : ComRenderRoot required .");
		return;
	}

	m_pAvatarRoot = cocos2d::Node::create();
	render->AddChild(m_pAvatarRoot);
	
	m_pBodyArmature = cocostudio::Armature::create(bodyFileName);
	m_pBodyArmature->getAnimation()->playWithIndex(0);
	m_pAvatarRoot->addChild(m_pBodyArmature);
}

ComBulletAnimBase::~ComBulletAnimBase()
{
	
}

void ComBulletAnimBase::OnDestroy()
{

}

