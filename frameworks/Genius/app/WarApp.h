

class WarApp
{
public:
	bool			Init();
	void			Tick(float time);
	void			Destroy();
	void			ShowSetting(bool show);
	void			ShowAuthor(bool show);
	void			SpawnOne(int team = 0);
	void			KillAll();

private:
	void			_Update_Fast(float time);
	void			_Update_Normal(float time);
	void			_Update_Slow(float time);

private:
	
};