#ifndef _GENIUS_GAME_PLAY_H_
#define _GENIUS_GAME_PLAY_H_

#include <string>

class GamePlay
{
public:
	static GamePlay& GetSingleton();
	bool Init();
	void Update(float time);
	void Destroy();

	void SendMonster();
	void SendHuman();

private:
	GamePlay(){}
	bool LoadFromConfig(std::string filePath);
};

#endif