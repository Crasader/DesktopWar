
#include "audio/include/SimpleAudioEngine.h"
#include "AudioManager.h"

using namespace Genius;


void AudioManager::PlayBGM(const std::string& filePath)
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic(filePath.c_str(), true);
}


void AudioManager::PlayEffect(const std::string& filePath)
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(filePath.c_str());
}


void AudioManager::Release()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->end();
}

