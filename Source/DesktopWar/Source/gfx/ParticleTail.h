#pragma once

#include "2d/CCParticleSystemQuad.h"

class ParticleTail : public cocos2d::ParticleSystemQuad
{
public:
	static ParticleTail* create();
	static ParticleTail* createWithTotalParticles(int numberOfParticles);

CC_CONSTRUCTOR_ACCESS:
	ParticleTail(){}
	virtual ~ParticleTail(){}

	bool init(){ return initWithTotalParticles(200); }
	virtual bool initWithTotalParticles(int numberOfParticles);

private:
	CC_DISALLOW_COPY_AND_ASSIGN(ParticleTail);
};