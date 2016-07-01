#pragma once

#include "AI/AI.h"
#include "event/EventManager.h"

USING_NS_AI
USING_NS_BHTREE


/************************************************************************/
/*                                                 PawnIdle                     */
/************************************************************************/
class PawnIdle : public BHTree::Action
{
public:
	PawnIdle();

	virtual eBehaviorStatus Update(BHUpdateContext& context);
	virtual void OnInitialize(BHUpdateContext& context);
	virtual void OnTerminate(BHUpdateContext& context, eBehaviorStatus state);
	virtual bool LoadFromXml(XMLElement* xml);

private:
	float		m_totalDuration;
	float		m_timeCounter;
	float		m_changeDirDuration;
	float		m_changeDirTimeCounter;
};


/************************************************************************/
/*                                                 PawnMove                     */
/************************************************************************/
class PawnMove : public BHTree::Action
{
public:
	PawnMove() :
		m_uiMaxTime(20)
	{}

	virtual eBehaviorStatus Update(BHUpdateContext& context);
	virtual void OnInitialize(BHUpdateContext& context);
	virtual void OnTerminate(BHUpdateContext& context, eBehaviorStatus state);
	virtual bool LoadFromXml(XMLElement* xml);

private:
	float		m_uiMaxTime;
	float		m_uiTimeCounter;
};


/************************************************************************/
/*                                                 PawnDie                     */
/************************************************************************/
class PawnDie : public BHTree::Action
{
public:
	PawnDie() :
		m_duration(2),
		m_timeCounter(0)
	{}

	virtual eBehaviorStatus Update(BHUpdateContext& context);
	virtual void OnInitialize(BHUpdateContext& context);
	virtual void OnTerminate(BHUpdateContext& context, eBehaviorStatus state);
	virtual bool LoadFromXml(XMLElement* xml);

private:
	float		m_duration;
	float		m_timeCounter;
};


/************************************************************************/
/*                                                 PawnWander                     */
/************************************************************************/
class PawnWander : public BHTree::Action
{
private:
	enum eWanderType
	{
		eWanderNone = 0,
		eWanderAround,
		eWanderLeft,
		eWanderRight,
		eWanderNum,
	};
public:
	PawnWander();

	virtual eBehaviorStatus Update(BHUpdateContext& context);
	virtual void OnInitialize(BHUpdateContext& context);
	virtual void OnTerminate(BHUpdateContext& context, eBehaviorStatus state);
	virtual bool LoadFromXml(XMLElement* xml);

private:
	void		GoToSomewhere(BHUpdateContext& context);

private:
	int		m_wanderType;
	float		m_totalDuration;
	float		m_timeCounter;
	float		m_changeDirDuration;
	float		m_changeDirTimeCounter;
};


/************************************************************************/
/*                                                 PawnChase                     */
/************************************************************************/
class PawnChase : public BHTree::Action
{
public:
	PawnChase();

	virtual eBehaviorStatus Update(BHUpdateContext& context);
	virtual void OnInitialize(BHUpdateContext& context);
	virtual void OnTerminate(BHUpdateContext& context, eBehaviorStatus state);
	virtual bool LoadFromXml(XMLElement* xml);

private:
	void		GoToTarget(BHUpdateContext& context);

private:
	float		m_relocateInterval;
	float		m_timeCounter;
};


/************************************************************************/
/*                    ÆÕÍ¨¹¥»÷¡¢½ü¾àÀë¹¥»÷PawnAttack                     */
/************************************************************************/
class PawnAttackNear : public BHTree::Action, public IEventListener
{
public:
	PawnAttackNear();
	~PawnAttackNear();

	virtual eBehaviorStatus Update(BHUpdateContext& context);
	virtual void OnInitialize(BHUpdateContext& context);
	virtual void OnTerminate(BHUpdateContext& context, eBehaviorStatus state);
	virtual bool LoadFromXml(XMLElement* xml);

	virtual bool HandleEvent(IEventData const &event);

private:
	int ownerEntityID;
	int attackAnimCount;
};

/************************************************************************/
/*                    ÆÕÍ¨¹¥»÷¡¢½ü¾àÀë ¸ß¼¶¹¥»÷PawnAttack                     */
/************************************************************************/
class PawnAttackNear2 : public BHTree::Action, public IEventListener
{
public:
	PawnAttackNear2();
	~PawnAttackNear2();

	virtual eBehaviorStatus Update(BHUpdateContext& context);
	virtual void OnInitialize(BHUpdateContext& context);
	virtual void OnTerminate(BHUpdateContext& context, eBehaviorStatus state);
	virtual bool LoadFromXml(XMLElement* xml);

	virtual bool HandleEvent(IEventData const &event);

private:
	int ownerEntityID;
	bool ComAnimationpleted;
};

/************************************************************************/
/*                    Ô¶¾àÀë¹¥»÷PawnAttack                     */
/************************************************************************/
class PawnAttackFar : public BHTree::Action, public IEventListener
{
public:
	PawnAttackFar();
	~PawnAttackFar();

	virtual eBehaviorStatus Update(BHUpdateContext& context);
	virtual void OnInitialize(BHUpdateContext& context);
	virtual void OnTerminate(BHUpdateContext& context, eBehaviorStatus state);
	virtual bool LoadFromXml(XMLElement* xml);

	virtual bool HandleEvent(IEventData const &event);

private:
	int ownerEntityID;
};


/************************************************************************/
/*                                                 ÌØÊâ¼¼1                     */
/************************************************************************/
class PawnSkill1 : public BHTree::Action, public IEventListener
{
public:
	PawnSkill1();
	~PawnSkill1();

	virtual eBehaviorStatus Update(BHUpdateContext& context);
	virtual void OnInitialize(BHUpdateContext& context);
	virtual void OnTerminate(BHUpdateContext& context, eBehaviorStatus state);
	virtual bool LoadFromXml(XMLElement* xml);

	virtual bool HandleEvent(IEventData const &event);

private:
	bool ComAnimationpleted;
	int		ownerEntityID;
};

/************************************************************************/
/*                                                 ÌØÊâ¼¼2                     */
/************************************************************************/
class PawnSkill2 : public BHTree::Action, public IEventListener
{
public:
	PawnSkill2();
	~PawnSkill2();

	virtual eBehaviorStatus Update(BHUpdateContext& context);
	virtual void OnInitialize(BHUpdateContext& context);
	virtual void OnTerminate(BHUpdateContext& context, eBehaviorStatus state);
	virtual bool LoadFromXml(XMLElement* xml);

	virtual bool HandleEvent(IEventData const &event);

private:
	bool ComAnimationpleted;
	int		ownerEntityID;
};

/************************************************************************/
/*                                                 ÌØÊâ¼¼3                     */
/************************************************************************/
class PawnSkill3 : public BHTree::Action, public IEventListener
{
public:
	PawnSkill3();
	~PawnSkill3();

	virtual eBehaviorStatus Update(BHUpdateContext& context);
	virtual void OnInitialize(BHUpdateContext& context);
	virtual void OnTerminate(BHUpdateContext& context, eBehaviorStatus state);
	virtual bool LoadFromXml(XMLElement* xml);

	virtual bool HandleEvent(IEventData const &event);

private:
	bool ComAnimationpleted;
	int		ownerEntityID;
};

/************************************************************************/
/*                                                      SheepIdle								               */
/************************************************************************/
/*class SheepIdle : public BHTree::Action
{
public:
	SheepIdle() :
		m_uiMaxIdleTime(3),
		m_uiIdleTimeCounter(0)
	{}

	virtual eBehaviorStatus Update(BHUpdateContext& context);
	virtual void OnInitialize(BHUpdateContext& context);
	virtual void OnTerminate(BHUpdateContext& context, eBehaviorStatus state);
	virtual bool LoadFromXml(XMLElement* xml);

private:
	float		m_uiMaxIdleTime;
	float		m_uiIdleTimeCounter;
};*/

/************************************************************************/
/*                                                 SheepEat                     */
/************************************************************************/
/*class SheepEat : public BHTree::Action
{
public:
	SheepEat() :
		m_uiMaxIdleTime(3),
		m_uiIdleTimeCounter(0)
	{}

	virtual eBehaviorStatus Update(BHUpdateContext& context);
	virtual void OnInitialize(BHUpdateContext& context);
	virtual void OnTerminate(BHUpdateContext& context, eBehaviorStatus state);
	virtual bool LoadFromXml(XMLElement* xml);

private:
	float		m_uiMaxIdleTime;
	float		m_uiIdleTimeCounter;
};*/

/************************************************************************/
/*                                                 SheepDie                     */
/************************************************************************/
/*class SheepDie : public BHTree::Action
{
public:
	SheepDie() :
		m_uiMaxIdleTime(3),
		m_uiIdleTimeCounter(0)
	{}

	virtual eBehaviorStatus Update(BHUpdateContext& context);
	virtual void OnInitialize(BHUpdateContext& context);
	virtual void OnTerminate(BHUpdateContext& context, eBehaviorStatus state);
	virtual bool LoadFromXml(XMLElement* xml);

private:
	float		m_uiMaxIdleTime;
	float		m_uiIdleTimeCounter;
};*/