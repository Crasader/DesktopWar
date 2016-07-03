

#include "RollNumberLabel.h"

USING_NS_CC;

RollNumberLabel* RollNumberLabel::create()
{
	RollNumberLabel* pRollNumberLabel = new RollNumberLabel();
	if (pRollNumberLabel)
		pRollNumberLabel->autorelease();

	pRollNumberLabel->m_rollSpeed= 100;
	pRollNumberLabel->m_pLabel = Label::createWithBMFont("res/font/arial16.fnt", "", TextHAlignment::CENTER);
	pRollNumberLabel->m_pLabel->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	pRollNumberLabel->addChild(pRollNumberLabel->m_pLabel);
	pRollNumberLabel->scheduleUpdate();

	return pRollNumberLabel;
}

void RollNumberLabel::update(float delta)
{
	if (m_pLabel == nullptr)
		return;

	m_timePassed += delta;

	if (m_targetNumber != (int)m_currentNumber && m_timePassed > 0.05f)
	{
		float count = m_timePassed / (1.0f / m_rollSpeed);;
		if (m_targetNumber > (int)m_currentNumber)
		{
			m_currentNumber += count;
			if (m_currentNumber > m_targetNumber)
				m_currentNumber = m_targetNumber;
		}
		else
		{
			m_currentNumber -= count;
			if (m_currentNumber < m_targetNumber)
				m_currentNumber = m_targetNumber;
		}

		m_timePassed = 0;
		
		std::stringstream stream;
		stream << (int)m_currentNumber << "%";
		m_pLabel->setString(stream.str());
	}

}

void RollNumberLabel::setColor(int r, int g, int b)
{
	m_pLabel->setColor(cocos2d::Color3B(r, g, b));
}

void RollNumberLabel::setStartNumber(int number)
{
	m_currentNumber = number;
	std::stringstream stream;
	stream << m_currentNumber << "%";
	m_pLabel->setString(stream.str());
}

void RollNumberLabel::rollTo(int number)
{
	m_targetNumber = number;
}
