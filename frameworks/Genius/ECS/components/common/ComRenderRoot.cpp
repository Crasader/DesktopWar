
#include "ComRenderRoot.h"
#include "../../core/ECSWorld.h"
#include "gfx/SceneManager.h"

using namespace Genius;
using namespace cocos2d;


COM_CREATE_FN_IMPL(ComRenderRoot);

void ComRenderRoot::OnAwake()
{
	rootNode = cocos2d::Node::create();
	SceneManager::GetSingleton()->AddToMapLayer(rootNode);
}

void ComRenderRoot::OnDestroy()
{
	if (rootNode)
	{
		rootNode->removeFromParent();
		rootNode = nullptr;
	}
}

ComRenderRoot::ComRenderRoot()
{
	rootNode = nullptr;
}

ComRenderRoot::~ComRenderRoot()
{
	
}

void ComRenderRoot::AddChild(cocos2d::Node* node)
{
	rootNode->addChild(node);
}

