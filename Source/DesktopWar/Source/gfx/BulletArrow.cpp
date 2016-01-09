
// d:)
#include "BulletArrow.h"

USING_NS_CC;

#define EPSION 0.0001f 
#define IS_EQUAL(val1, val2)  (fabs((val1) - (val2)) <= EPSION)
const int mDirections = 16;
/*
BulletArrow::BulletArrow():
mDegree(0),
mSpeed(30)
{

}

BulletArrow* BulletArrow::create()
{
	BulletArrow* ret = new (std::nothrow) BulletArrow();
	if (ret && ret->init())
	{
		ret->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(ret);
	}
	return ret;
}

bool BulletArrow::init()
{
	// �������ķ��ж���,���ж��ٸ����򣬾ʹ������ٸ�����
	int flyFrames = 7;
	int frame_width = 20;
	int frame_height = 20;
	//Texture2D* pTexture = Director::getInstance()->getTextureCache()->addImage("res/img/arrowFrames.png");
	std::string fileName = "res/img/arrowFrames.png";
	for (int i = 0; i < mDirections; ++i)
	{
		// �����ж��� 
		Array* spriteFramesArray = Array::createWithCapacity(flyFrames);

		// ��ͼƬ��ÿһ֡��λ��������CCSpriteFrame
		for (int j = 0; j < flyFrames; ++j)
		{
			SpriteFrame* frame = SpriteFrame::create(fileName, Rect(j * frame_width, i * frame_height, frame_width, frame_height));
			spriteFramesArray->addObject(frame);
		}

		//�Լ�ֵ��ʽ����������AnimationCatch��
		float frameTime = 1.f / (mSpeed * flyFrames);
		Animation* animation = Animation::(spriteFramesArray, frameTime);

		std::string name = getArrowAnimateName(i);
		AnimationCache::sharedAnimationCache()->addAnimation(animation, name);

		spriteFramesArray->removeAllObjects();
		spriteFramesArray->release();
	}
	return true;
}

void BulletArrow::StartFly(float control_height, cocos2d::Vec2& ptRelativeTarget)
{
	// ���ż����ж���
	std::string name = getArrowAnimateName(dir);
	Animation* animation = AnimationCache::sharedAnimationCache()->animationByName(name.c_str());

	Animate* animate = Animate::create(animation);
	this->runAction(animate);

	// ���bezier
	ccBezierConfig cfg;
	cfg.controlPoint_1 = ccp(0, control_height);
	cfg.controlPoint_2 = ccp(ptRelativeTarget.x, ptRelativeTarget.y + control_height);
	cfg.endPosition = ptRelativeTarget;

	// ���ű����������ƶ�
	ActionInterval* bezierForward = BezierBy::create(2.f, cfg);
	ActionInterval* seq = (ActionInterval*)Sequence::create(bezierForward,
		CCCallFunc::create(this, callfunc_selector(BulletArrow::arrowFlyOverCallBack)),
		nullptr);

	this->runAction(seq);
}

void BulletArrow::arrowFlyOverCallBack()
{
	this->stopAllActions();

	//Animate* animate = Animate::create(animation);
	//this->runAction(CCRepeatForever::create(animate));

	CCActionInterval* delay = CCDelayTime::create(2);
	CCActionInterval* seq = (CCActionInterval*)CCSequence::create(delay,
		CCCallFunc::create(this, callfuncND_selector(BulletArrow::arrowDisappearedCallBack)),
		nullptr);

	this->runAction(seq);
}

void BulletArrow::arrowDisappearedCallBack()
{
}

// ���·���,������ʼ�����ֹ�㣬����actan���������Ļ��ȣ�Ȼ��ת��Ϊ�Ƕ�

int BulletArrow::updateDirection(const cocos2d::Vec2& ptRole, const cocos2d::Vec2& ptTarget)
{
	Vec2 sub = ccpSub(ptTarget, ptRole);

	if (IS_EQUAL(sub.x, 0.f) && IS_EQUAL(sub.y, 0.f))
		return -1;

	if (IS_EQUAL(sub.y, 0.f) && sub.x > 0)
	{
		mDegree = 90.f;
	}
	else if (IS_EQUAL(sub.y, 0.f) && sub.x < 0)
	{
		mDegree = 180.f;
	}
	else
	{
		// ����ת�Ƕ�
		float radians = atanf(sub.x / sub.y);
		mDegree = CC_RADIANS_TO_DEGREES(radians);

		if (sub.x >= 0 && sub.y >= 0)          // ��һ����
		{

		}
		else if (sub.x >= 0 && sub.y <= 0)      // �ڶ�����
		{
			mDegree += 180.f;
		}
		else if (sub.x <= 0 && sub.y <= 0)      // ��������
		{
			mDegree += 180.f;
		}
		else                                   // ��������
		{
			mDegree += 360.f;
		}
	}

	if (mDegree < 0.f)
		mDegree = 0.f;
	if (mDegree > 360.f)
		mDegree = 0.f;

	float single = (float)360 / 16;
	for (int i = 0; i < mDirections; ++i)
	{
		if (mDegree >= i * single && mDegree <= (i + 1) * single)
			return mDirections;
	}

	return mDirections - 1;
}

std::string BulletArrow::getArrowAnimateName(int dir)
{
	char dirstr[8];
	sprintf(dirstr, "%d", dir);
	std::string name = "BulletArrow";
	name += dirstr;
	return name;
}

void BulletArrow::update(float delta)
{
	int dir = updateDirection();
}
*/