
#pragma once

#include <string>


namespace Genius
{
	class ComPawnAnim;

	class AnimSet
	{
	public:

		AnimSet(ComPawnAnim*	pComPawnAnim);

		virtual ~AnimSet();

		virtual bool HaveAnim(const std::string& name);

		virtual const std::string& GetIdleAnim(int direction) = 0;

		virtual const std::string& GetMoveAnim(int direction) = 0;

		virtual const std::string& GetDieAnim(int direction) = 0;

		virtual const std::string& GetAttackNearAnim(int direction) = 0;

		virtual const std::string& GetAttackFarAnim(int direction) = 0;

		virtual const std::string& GetSkill1Anim(int direction) = 0;

		virtual const std::string& GetSkill2Anim(int direction) = 0;

		virtual const std::string& GetSkill3Anim(int direction) = 0;

	protected:
		ComPawnAnim*	m_pComPawnAnim;

	};
}
