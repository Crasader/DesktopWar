#pragma once
#include "app/GameDefine.h"

namespace GameUtils
{
	int CalculateAreaID(int posX, int posY)
	{
		return posX / GameDefine::singleAreaWidth + posY / GameDefine::singleAreaHeight * GameDefine::areaCountY;
	}

	bool IsInAreasAround(int centerAreaID, int posX, int posY)
	{
		int otherAreaID = CalculateAreaID(posX, posY);
		return otherAreaID == centerAreaID
			|| otherAreaID == centerAreaID - 1
			|| otherAreaID == centerAreaID + 1
			|| otherAreaID == centerAreaID - GameDefine::areaCountY
			|| otherAreaID == centerAreaID - GameDefine::areaCountY - 1
			|| otherAreaID == centerAreaID - GameDefine::areaCountY + 1
			|| otherAreaID == centerAreaID + GameDefine::areaCountY
			|| otherAreaID == centerAreaID + GameDefine::areaCountY - 1
			|| otherAreaID == centerAreaID + GameDefine::areaCountY + 1;
	}
};
