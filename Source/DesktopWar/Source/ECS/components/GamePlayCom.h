#pragma once

#include "../Component.h"

namespace Genius
{
	/************************************************************************/
	/*                                     GameControlCom                                 */
	/************************************************************************/
	class GameControlCom : public Component
	{
	public:
		float		gameTimePassed;
		float		lastSpawnTime;
		int		population;

	public:
		GameControlCom() :
			gameTimePassed(0),
			lastSpawnTime(0),
			population(0)
		{}
		virtual ~GameControlCom();
	};

	/************************************************************************/
	/*                                     HumanGameControlCom                                 */
	/************************************************************************/
	class HumanGameControlCom : public GameControlCom
	{
	public:
		const static int		maxHumanPopulation;

	public:
		HumanGameControlCom();
		virtual ~HumanGameControlCom();
	};

	/************************************************************************/
	/*                                     MonsterGameControlCom                                 */
	/************************************************************************/
	class MonsterGameControlCom : public GameControlCom
	{
	public:
		const static int		maxMonsterPopulation;

	public:
		MonsterGameControlCom();
		virtual ~MonsterGameControlCom();
	};
};
