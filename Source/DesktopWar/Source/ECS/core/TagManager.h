#pragma once

#include <unordered_map>
#include <string>

namespace Genius
{
	class Entity;

	class TagManager
	{
		private:
			std::unordered_map<std::string, Entity*> tagByEntity;

		public:
			TagManager();
			void			Subscribe(const std::string tag, Entity* e);
			void			UnSubscribe(const std::string tag);
			bool			IsSubscribed(const std::string tag);
			Entity &	GetEntity(const std::string tag);
			void			Remove(Entity* e);
	};
};
