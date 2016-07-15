#pragma once

#include <unordered_map>
#include <string>

namespace Genius
{
	class Entity;
	typedef std::unordered_map<int, Entity*> entity_map;
	class TagManager
	{
	private:
		std::unordered_map<std::string, entity_map> tagMap;

	public:
		TagManager();
		void			Subscribe(const std::string& tag, Entity* entity);
		void			UnSubscribe(const std::string& tag, Entity* entity);
		bool			IsSubscribed(const std::string& tag, Entity* entity);
		entity_map& GetEntitys(const std::string& tag);
		void			Remove(Entity* entity);
	};
};
