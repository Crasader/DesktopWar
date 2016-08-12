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


	// Tags
	const std::string Tag_Collider = "Collider";
	const std::string Tag_Soldier = "Soldier";
	const std::string Tag_Monster = "Monster";
	
};
