#ifndef _GENIUS_SCENE_H_
#define _GENIUS_SCENE_H_

#include "cocos2d.h"
#include "common/Singleton.h"
#include <list>
#include "event/Event.h"


namespace Genius
{
	struct EntityNodeData
	{
		int entityID;
		cocos2d::Node* node;
	};

	class SceneManager : public IEventListener
	{
	public:
		static  SceneManager*  GetSingleton();
		bool Init();
		void Update();
		void AddToRoot(cocos2d::Node* node, float x = 0, float y = 0, int zOrder = 0);
		void AddToMapLayer(cocos2d::Node* node, float x = 0, float y = 0, int zOrder = 0);
		void AddToUILayer(cocos2d::Node* node, float x = 0, float y = 0, int zOrder = 0);
		cocos2d::Node* GetMapLayer(){ return m_pMapLayer; }
		cocos2d::Node* GetUILayer(){ return m_pUILayer; }
		void ShakeScene(int strength = 6, float time = 0.2f);

		virtual bool HandleEvent(IEventData const &evt);

	private:
		void RefreshPawnsZOrder();
		void UpdateSceneShake();

	private:
		cocos2d::Node*	m_root;
		cocos2d::LayerColor*	m_pMapLayer;
		cocos2d::Node*	m_pUILayer;
		bool						m_bShakeScene;
		int						m_shakeSceneBeginTime;
		int						m_shakeStrength;
		float						m_shakeTime;

		
		std::list<EntityNodeData>	m_entityNodes;
	};

};

#endif