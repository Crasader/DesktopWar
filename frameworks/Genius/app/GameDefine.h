#pragma once

#include <string>

namespace GameDefine
{
	// 绘制区域大小
	extern int viewWidth;
	extern int viewHeight;

	// 给整个区域分小区，在小区内进行碰撞检测，以减少计算。
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
