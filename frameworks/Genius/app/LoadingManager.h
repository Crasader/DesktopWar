
#pragma  once

#include <vector>
#include <string>
#include "gfx/gfx.h"

//class AppStateLoading;
class LoadingManager : public cocos2d::Ref
{
public:
	enum ResourceType
	{
		Json,
		Image,
	};

	struct ResourceInfo
	{
		ResourceType	type;
		std::string			path;
		ResourceInfo(ResourceType t, std::string& str) :
			type(t),
			path(str)
		{}
	};

	typedef std::vector<ResourceInfo> ResourceList;


public:
	LoadingManager(/*AppStateLoading* pState*/);
	~LoadingManager();

	void GenerateUnLoadList();
	void ClearLoadingList();
	void AddResource(ResourceType t, std::string& path);
	void StartLoading();

	// false��ʾȫ���������
	void UpdateLoading();
	bool IsLoadingDone();
	int	GetLoadingPercent();

private:
	void JsonLoadedCallback(float f);
	void PlistImageLoadedCallback(cocos2d::Texture2D* texture);
	void ImageLoadedCallback(cocos2d::Texture2D* texture);

private:
	ResourceList						m_resources;
	ResourceList						m_unloadResources;
	ResourceList::iterator		m_currentIterator;
	unsigned int						m_loadedCount;
	//AppStateLoading*			m_pLoadingState;
};