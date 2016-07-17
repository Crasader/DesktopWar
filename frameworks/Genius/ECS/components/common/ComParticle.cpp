
#include "ComParticle.h"
#include "ecs/components/common/ComRenderRoot.h"
#include "../../core/ECSWorld.h"
#include "Log.h"


using namespace Genius;
USING_NS_CC;


COM_CREATE_FN_IMPL(ComParticle);

void ComParticle::Create(const std::string& fileName)
{
	auto render = GetEntity()->GetComponent<ComRenderRoot>();
	if (nullptr == render)
	{
		Log::Error("ComPawnAnim.create : ComRenderRoot required .");
		return;
	}

	auto smoke = ParticleSmoke::create();
	smoke->setTexture(Director::getInstance()->getTextureCache()->addImage(fileName));
	smoke->setPosition(Vec2(0, 0));
	smoke->setTotalParticles(130);
	smoke->setLife(2.0f);

	m_pAvatarRoot = cocos2d::Node::create();
	m_pAvatarRoot->addChild(smoke);

	render->AddChild(m_pAvatarRoot);
}

ComParticle::~ComParticle()
{
	
}
