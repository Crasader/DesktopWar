#ifndef _GENIUS_BUFF_H_
#define _GENIUS_BUFF_H_

#include <vector>

namespace cfg
{
	class Buff_cfg;
}

namespace Genius
{
	enum EBuffPileType
	{
		Pile_None,
		Pile_Replace,
		Pile_OnlyOne,
		Pile_JustDoIt,
	};

	/*struct Effect
	{
		Effect()
		{
			effected = false;
		}
		bool effected;
		BuffAction action;
	};*/

	enum EffectCycleType
	{
		EffectCycle_Interval,
		EffectCycle_Point,
	};

	/*struct EffectCycle
	{
		EffectCycle()
		{
			m_cycleType = 0;
			m_interval = 0;
		}
		int m_cycleType;
		int m_interval;
		BuffAction action;
	};
	*/
	enum EbuffRet
	{
		EBuffRet_Invalid = -1,
		EBuffRet_False = 0,
		EBuffRet_True = 1<<0,
		EBuffRet_Keep = 1<<1,
		EBuffRet_Kill = 1 << 2,
	};

	
	
	class Buff
	{
	public:
		friend class BuffSet;

		enum EBuffModType
		{
			EBuffMod_None = 0,
			EBuffMod_Add = 1,
			EBuffMod_Dec = 2,
		};

	public:
		Buff();

		bool		Init(int cfg);
		int		Update(float elapse);

		int		AddPile();
		int		RemovePile();
		void		RemoveAllPile();

	public:
		int		GetInstID(){ return m_instID; }
		void		SetInstID(int id){ m_instID = id; }
		bool		IsAlive();
		cfg::Buff_cfg* GetCfg(){ return m_cfg; }
		int		GetSeries();
		int		GetPileType();
		float		GetMaxPersist();
		int		GetSender(){ return m_senderID; }
		int		GetReceiver(){ return m_receiverID; }
		int		GetModType();

	private:
		bool Begin();
		bool End();
		bool BeginEffect();
		bool EndEffect();

	private:
		cfg::Buff_cfg*			m_cfg;
		int				m_senderID;
		int				m_receiverID;
		int				m_instID;
		float				m_duration;
		float				m_life;
		float				m_lastActionTime;
		int				m_curPileCount;
		int				m_skillID;
		bool				m_alive;
		int				m_cycleCount;
		/*std::vector<Effect>			m_beginActions;
		std::vector<EffectCycle>	m_cycleActions;
		std::vector <Effect>			m_effectActions;
		std::vector <Effect>			m_endActions;*/
	};

}

#endif