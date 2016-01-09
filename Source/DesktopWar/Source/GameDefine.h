#pragma once

#include <string>

namespace GameDefine
{
	// ���������С
	extern int viewWidth;
	extern int viewHeight;

	// �����������С������С���ڽ�����ײ��⣬�Լ��ټ��㡣
	const int singleAreaWidth = 200;
	const int singleAreaHeight = 200;
	const int areaCountX = 10;
	const int areaCountY = 10;

	// zorder
	const int mapRootZOrder = 1;
	const int uiRootZOrder = 2;

	// Tag
	const std::string Tag_HumanBornPoint = "HumanBP";
	const std::string Tag_MonsterBornPoint = "MonsterBP";

	// Group
	const std::string Group_Human = "HumanGP";
	const std::string Group_Monster = "MonsterGP";
	
};
