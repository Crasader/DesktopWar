#ifndef _ROLL_NUMBER_LABEL_
#define _ROLL_NUMBER_LABEL_

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class RollNumberLabel : public cocos2d::Node
{
public:
	RollNumberLabel():
		m_pLabel(nullptr),
		m_rollInterval(0),
		m_timePassed(0),
		m_currentNumber(0),
		m_targetNumber(0)
	{}
	virtual ~RollNumberLabel(){}
	static RollNumberLabel *create();
	virtual void update(float delta);
	void setColor(int r, int g, int b);
	void setStartNumber(int number);
	void rollTo(int number);
	bool isRollDone(){ return m_currentNumber == m_targetNumber; }

private:
	cocos2d::Label* m_pLabel;
	float					m_rollInterval;	// ����+1�����ʱ��/s
	float					m_timePassed;	// ������ʱ
	int					m_currentNumber;
	int					m_targetNumber;
};

#endif