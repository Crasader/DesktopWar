
#include "AnimFSMSimple.h"
#include "../animState/AnimStateIdle.h"

using namespace Genius;

AnimFSMSimple::AnimFSMSimple(ComPawnAnim* pComPawnAnim) :
AnimFSM(pComPawnAnim)
{
	
}

AnimFSMSimple::~AnimFSMSimple()
{

}

void AnimFSMSimple::Initialize()
{
	Release();
	m_animStateList.push_back(new AnimStateIdle(m_pComPawnAnim));
}

void AnimFSMSimple::DoAction()
{

}