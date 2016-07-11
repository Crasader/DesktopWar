
#pragma once

#include "../core/EntityProcessingSystem.h"
#include "../core/ComponentMapper.h"
#include "../components/ComEntityScript.h"


namespace Genius
{
	class SystemEntityScript : public EntityProcessingSystem
	{
	private:
		ComponentMapper<ComEntityScript>	scriptMapper;

	public:
		SystemEntityScript()
		{
			SetComponentTypes<ComEntityScript>();
		}
		virtual const char* GetName(){ return "SystemEntityScript"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* entity);
	};
};
