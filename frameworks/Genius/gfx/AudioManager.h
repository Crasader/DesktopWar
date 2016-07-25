#pragma once


#include "common/Singleton.h"
#include <string>


namespace Genius
{

	class AudioManager : public Singleton<AudioManager>
	{
	public:
		void PlayBGM(const std::string& filePath);
		void PlayEffect(const std::string& filePath);
		void Release();
	};

}