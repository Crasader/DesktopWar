#include "../BaseConfig.h"

namespace cfg
{
	class Animation_cfg : public BaseConfig
	{
	public:

		DECLARE_CONFIG_CREATE(Animation_cfg)

		string filePath;

		virtual int Init(Genius::TabFile& reader, int row, int col)
		{
			filePath = "";
			if(reader.GetStringValue(row, col).length() > 0)
				filePath = reader.GetStringValue(row, col++);

			return col;
		}
	};

IMPL_CONFIG_CREATE(Animation_cfg)

};