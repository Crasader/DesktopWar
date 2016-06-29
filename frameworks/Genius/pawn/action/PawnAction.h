
#pragma once

namespace Genius
{
	enum ePawnActionState
	{
		PAS_Active = 1,
		PAS_Success,
		PAS_Failed,
		PAS_Unused,
	};

	class PawnAction
	{
	public:

		PawnAction();

		virtual ~PawnAction();

		virtual void Reset();

		int GetType(){ return m_actionType; }

		bool IsActive(){ return m_currentState == PAS_Active; }

		bool IsSuccess(){ return m_currentState == PAS_Success; }

		bool IsFailed(){ return m_currentState == PAS_Failed; }

		bool IsUnused(){ return m_currentState == PAS_Unused; }

		void SetActive(){ m_currentState = PAS_Active; }

		void SetSuccess(){ m_currentState = PAS_Success; }

		void SetFalied(){ m_currentState = PAS_Failed; }

		void SetUnused(){ m_currentState = PAS_Unused; }

	protected:

		int		m_actionType;

		ePawnActionState	m_currentState;

	};

}