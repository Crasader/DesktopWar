#ifndef _GENIUS_SCENE_H_
#define _GENIUS_SCENE_H_

#include "cocos2d.h"
#include "common/Singleton.h"

namespace Genius
{
	class SceneManager
	{
	public:
		static  SceneManager*  GetSingleton();
		bool Init();
		void Update();
		void AddToMapLayer(cocos2d::Node* node, float x = 0, float y = 0, int zOrder = 0);
		cocos2d::Node* GetMapLayer(){ return m_pMapLayer; }
		void ShakeScene(int strength = 6, float time = 0.2f);

	private:
		void RefreshPawnsZOrder();
		void UpdateSceneShake();

	private:
		cocos2d::Node*	m_root;
		cocos2d::LayerColor*	m_pMapLayer;
		bool						m_bShakeScene;
		int						m_shakeSceneBeginTime;
		int						m_shakeStrength;
		float						m_shakeTime;
	};

};

#endif