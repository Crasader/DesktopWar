
#pragma once

#include <string>
#include "../../core/Component.h"
#include "pawn/PawnDefines.h"
#include "common/2Ddef.h"
#include "gfx/gfx.h"

namespace Genius
{

	class PawnDirectionCom : public Component
	{
	public:
		unsigned int	m_faceDir;
		unsigned int	m_lastFaceDir;

	public:
		PawnDirectionCom()
		{
			m_lastFaceDir = Face_Left;
			m_faceDir = Face_Left;
		}
	};

	

};
