
#pragma once

class WarApp
{
public:
	bool			Init();
	void			Tick(float timeSecond);
	void			Destroy();
	void			ShowSetting(bool show);
	void			ShowAuthor(bool show);
	void			SpawnOne(int team = 0);
	void			KillAll();

public:
	void			_logicThread();

private:
	void			_Update_Fast(float time);
	void			_Update_Normal(float time);
	void			_Update_Slow(float time);

private:
	bool		running;
};