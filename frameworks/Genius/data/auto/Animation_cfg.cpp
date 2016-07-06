#include "Animation_cfg.hpp"

using namespace cfg;

IMPL_CONFIG_CREATE(Animation_cfg);

		int Animation_cfg::Init(Genius::TabFile& reader, int row, int col)
		{
			filePath = "";
			if(reader.GetStringValue(row, col).length() > 0)
				filePath = reader.GetStringValue(row, col++);

			return col;
		}
