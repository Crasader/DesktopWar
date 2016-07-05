#include "../BaseConfig.h"

namespace cfg
{
	class BuffAction_cfg : public BaseConfig
	{
	public:

		DECLARE_CONFIG_CREATE(BuffAction_cfg)

		int type;
		string function;
		int param1;
		int param2;
		int param3;

		virtual int Init(Genius::TabFile& reader, int row, int col)
		{
			type = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				type = reader.GetIntValue(row, col++);

			function = "";
			if(reader.GetStringValue(row, col).length() > 0)
				function = reader.GetStringValue(row, col++);

			param1 = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				param1 = reader.GetIntValue(row, col++);

			param2 = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				param2 = reader.GetIntValue(row, col++);

			param3 = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				param3 = reader.GetIntValue(row, col++);

			return col;
		}
	};

IMPL_CONFIG_CREATE(BuffAction_cfg)

};