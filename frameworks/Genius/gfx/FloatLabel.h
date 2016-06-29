#ifndef _FLOAT_LABEL_
#define _FLOAT_LABEL_

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class FloatLabel : public cocos2d::Node
{
public:
	FloatLabel(){}
	virtual ~FloatLabel(){}
	static FloatLabel *create(const std::string& number);
	void EndCallback();

	void setColor(const cocos2d::Color3B& color);

private:
	cocos2d::Label* m_pLabel;
	
};

#endif