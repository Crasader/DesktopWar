
#pragma once

namespace Genius
{
	class ComPawnAnim;
	class PawnAction;

	class AnimState
	{
	public:

		AnimState(ComPawnAnim* comAnim);

		virtual ~AnimState();

		virtual void OnActive();

		virtual void OnDeactive();

		virtual void Update();

		virtual void Initialize();

		virtual void Release();

		virtual bool HandleNewAction(PawnAction* pAction);

	public:

		void SetFinished(bool value){ m_isFinished = value; }

		bool GetFinished(){ return m_isFinished; }

	protected:
		ComPawnAnim*		m_pComPawnAnim;

	private:
		bool		m_isFinished;
	};

}