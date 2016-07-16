
#pragma once


#include <string>
#include "app/GameDefine.h"

namespace Genius
{
	class Entity;
}

using namespace Genius;


class EntityUtility
{

public:

	const static std::string& GetEnemyTag(const std::string& myTag);

	static bool IsTagged(const std::string& tag, Entity* entity);

};

