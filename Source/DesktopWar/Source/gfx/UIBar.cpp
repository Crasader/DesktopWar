
// d:)
#include "UIBar.h"


const char* shortHpBarFore = "res/img/short.png";
const char* shortHpBarBack = "res/img/shortBG.png";
const char* mediumHpBarFore = "res/img/medium.png";
const char* mediumHpBarBack = "res/img/mediumBG.png";
const char* longHpBarFore = "res/img/big.png";
const char* longHpBarBack = "res/img/bigBG.png";
const char* bossHpBarFore = "res/img/large.png";
const char* bossHpBarBack = "res/img/largeBG.png";


UIBar* UIBar::create(int sizeType)
{
	const char* foreImg = shortHpBarFore;
	const char* backImg = shortHpBarBack;
	switch (sizeType)
	{
	case 1:
		foreImg = shortHpBarFore;
		backImg = shortHpBarBack;
		break;
	case 2:
		foreImg = mediumHpBarFore;
		backImg = mediumHpBarBack;
		break;
	case 3:
		foreImg = longHpBarFore;
		backImg = longHpBarBack;
		break;
	case 4:
		foreImg = bossHpBarFore;
		backImg = bossHpBarBack;
		break;
	}

	UIBar* pBar = new UIBar(foreImg, backImg);
	if (pBar)
		pBar->autorelease();

	return pBar;
}

UIBar::UIBar(const char* foregroundImage, const char* backgroundImage)
{
	m_pLoadingBar = nullptr;
	m_pBackground = nullptr;

	if(foregroundImage)
		m_pLoadingBar = cocos2d::ui::LoadingBar::create();

	if(m_pLoadingBar)
	{
		m_pLoadingBar->loadTexture(foregroundImage);
		m_pLoadingBar->setPercent(100);
		m_pLoadingBar->setPosition(cocos2d::Point(0, 0));
		this->addChild(m_pLoadingBar, 3);
	}

	if(backgroundImage)
		m_pBackground = cocos2d::Sprite::create(backgroundImage);

	if(m_pBackground)
	{
		m_pBackground->setPosition(cocos2d::Point(0, 0));
		m_pBackground->setOpacity(255);// ÉèÖÃÍ¸Ã÷¶È
		this->addChild(m_pBackground, 2);

		this->setContentSize(m_pBackground->getContentSize());
		m_size = m_pBackground->getContentSize();
	}
}

UIBar::~UIBar()
{

}

void UIBar::setPercent(int per)
{
	if(per<0)
		per = 0;
	else if(per > 100)
		per = 100;

	if(m_pLoadingBar)
		m_pLoadingBar->setPercent((float)per);
}

void UIBar::setSize(int width, int height)
{
	if(width < 0 || height < 0)
		return;

	if(m_pBackground && m_pLoadingBar)
	{
		m_pBackground->setScaleX(width/m_size.width);
		m_pBackground->setScaleY(height/m_size.height);

		m_pLoadingBar->setScaleX(width/m_size.width);
		m_pLoadingBar->setScaleY(height/m_size.height);
	}
}

void UIBar::setLength(int length)
{
	this->setSize(length, (int)m_size.height);
}

// void UIBar::setColor(ccColor3B color)
// {
// 	if(m_pLoadingBar)
// 		m_pLoadingBar->setColor(color);
// }
