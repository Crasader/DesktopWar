#ifndef _GENIUS_ENTITY_CREATORS_H_
#define _GENIUS_ENTITY_CREATORS_H_

#include <string>

namespace Genius
{
	class Entity;

	class EntityCreator
	{
	public:
		static int CreatePawn(int id, float x, float y, int team);
		//static Entity* CreatePawn(std::string id, float x, float y, int team);
		static int CreateBullet(int bulletID, int targetEntityID, float x, float y, int team, float destX, float destY);
		static int CreateBornPoint(float x, float y, int team);
	};
};

#endif