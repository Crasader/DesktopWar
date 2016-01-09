
// d:)
#include "RollNumberLabel.h"

USING_NS_CC;

RollNumberLabel* RollNumberLabel::create()
{
	RollNumberLabel* pRollNumberLabel = new RollNumberLabel();
	if (pRollNumberLabel)
		pRollNumberLabel->autorelease();

	pRollNumberLabel->m_rollInterval = 0.003f;
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

	if (m_targetNumber != m_currentNumber)
	{
		m_timePassed += delta;
		if (m_timePassed > m_rollInterval)
		{
			m_timePassed = 0;
			if (m_targetNumber > m_currentNumber)
				m_currentNumber++;
			else
				m_currentNumber--;
			std::stringstream stream;
			stream << m_currentNumber << "%";
			m_pLabel->setString(stream.str());
		}
	}

}

void RollNumberLabel::setColor(const Color3B& color)
{
	m_pLabel->setColor(color);
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
	//m_currentNumber = m_targetNumber;
	m_targetNumber = number;
}
