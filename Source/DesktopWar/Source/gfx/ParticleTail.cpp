
// d:)
#include "ParticleTail.h"
#include "base/CCDirector.h"
#include "base/firePngData.h"
#include "renderer/CCTextureCache.h"

USING_NS_CC;

ParticleTail* ParticleTail::create()
{
	ParticleTail* ret = new (std::nothrow) ParticleTail();
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

ParticleTail* ParticleTail::createWithTotalParticles(int numberOfParticles)
{
	ParticleTail* ret = new (std::nothrow) ParticleTail();
	if (ret && ret->initWithTotalParticles(numberOfParticles))
	{
		ret->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(ret);
	}
	return ret;
}

bool ParticleTail::initWithTotalParticles(int numberOfParticles)
{
	if (ParticleSystemQuad::initWithTotalParticles(numberOfParticles))
	{
		// duration
		_duration = DURATION_INFINITY;

		// Emitter mode: Gravity Mode
		setEmitterMode(Mode::GRAVITY);

		// Gravity Mode: gravity
		setGravity(Vec2(0, 0));

		// Gravity Mode: radial acceleration
		setRadialAccel(0);
		setRadialAccelVar(0);

		// Gravity Mode: speed of particles
		setSpeed(2);
		setSpeedVar(1);

		// angle
		_angle = 5;
		_angleVar = 2;

		// emitter position
		this->setPosition(0, 0);
		setPosVar(Vec2(2, 2));

		// life of particles
		_life = 1;
		_lifeVar = 0.2f;

		// size, in pixels
		_startSize = 10.0f;
		_startSizeVar = 4.0f;
		_endSize = 16.0f;
		_endSizeVar = 2.0f;

		// emits per frame
		_emissionRate = _totalParticles / _life * 0.7f;

		// color of particles
		_startColor.r = 1;
		_startColor.g = 1;
		_startColor.b = 1;
		_startColor.a = 1;
		_startColorVar.r = 0.02f;
		_startColorVar.g = 0.02f;
		_startColorVar.b = 0.02f;
		_startColorVar.a = 0.3f;
		_endColor.r = 1;
		_endColor.g = 1;
		_endColor.b = 1;
		_endColor.a = 0.2f;
		_endColorVar.r = 0.0f;
		_endColorVar.g = 0.0f;
		_endColorVar.b = 0.0f;
		_endColorVar.a = 0.0f;
		
		// additive
		this->setBlendAdditive(false);
		return true;
	}
	return false;
}
