
// d:)
#include "FloatLabel.h"

USING_NS_CC;

FloatLabel* FloatLabel::create(const std::string& number)
{
	FloatLabel* pFloatLabel = new FloatLabel();
	if (pFloatLabel)
		pFloatLabel->autorelease();

	pFloatLabel->m_pLabel = Label::createWithBMFont("res/font/arial16.fnt", number, TextHAlignment::CENTER);
	pFloatLabel->m_pLabel->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	pFloatLabel->addChild(pFloatLabel->m_pLabel);

	auto act = Sequence::create(MoveBy::create(0.2f, Vec2(0, 10)),
		//CallFunc::create(std::bind(&FloatLabel::EndCallback, pFloatLabel)),
		CallFunc::create(CC_CALLBACK_0(FloatLabel::EndCallback, pFloatLabel)),
		nullptr);
	pFloatLabel->m_pLabel->runAction(act);

	return pFloatLabel;
}

void FloatLabel::EndCallback()
{
	this->removeAllChildrenWithCleanup(true);
	this->removeFromParentAndCleanup(true);
}

void FloatLabel::setColor(const Color3B& color)
{
	m_pLabel->setColor(color);
}
