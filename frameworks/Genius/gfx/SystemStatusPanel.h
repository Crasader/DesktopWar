#pragma once

#include "cocos2d.h"
#include <string>
#include <vector>

class SystemStatusPanel
{
public:
	static SystemStatusPanel* GetSingleton();
	bool Init();
	void Update();

	void ClearStatus();
	void PrintStatus(std::string& name, std::string& state);
	void PrintStatus(std::string& name, float state);
	void PrintStatus(std::string& name, int state);

private:
	SystemStatusPanel(){}
	void AddNewLine();

private:
	cocos2d::LayerColor*	m_pRootLayer;
	std::vector<cocos2d::Label*>	m_labels;
	int						m_lineCount;
	int						m_currentLine;
	const static int		m_lineHeight;
	const static int		m_panelWidth;

	cocos2d::DrawNode*	pDrawNode;
};