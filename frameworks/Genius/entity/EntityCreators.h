#ifndef _GENIUS_ENTITY_CREATORS_H_
#define _GENIUS_ENTITY_CREATORS_H_

#include <string>

namespace Genius
{
	class Entity;

	class EntityCreator
	{
	public:
		static int CreatePawn(int id, float x, float y, const std::string& tag);
		static int CreateBullet(int bulletID, int targetEntityID, float x, float y, const std::string& tag, float destX, float destY);
		
	};
};

#endif