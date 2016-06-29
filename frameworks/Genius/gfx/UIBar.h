#ifndef _UI_BAR_
#define _UI_BAR_

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class UIBar : public cocos2d::Node
{
public:
	UIBar(const char* foregroundImage, const char* backgroundImage);
	virtual ~UIBar();

public:
	void setPercent(int v);
	void setSize(int width, int height);
/*	void setColor(ccColor3B color);*/
	void setLength(int length);

	static UIBar *create(int sizeType);

private:
	cocos2d::ui::LoadingBar*		m_pLoadingBar;
	cocos2d::Sprite*						m_pBackground;
	cocos2d::Size							m_size;
};

#endif