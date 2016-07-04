#include "../BaseConfig.h"

namespace cfg
{
	class anim_cfg : public BaseConfig
	{
	public:

		DECLARE_CONFIG_CREATE(anim_cfg)

		int number1;
		float number2;
		double number3;
		long number4;
		bool number5;
		string filePath;
		int number6[3];
		float number7[3];
		string number8[3];

		virtual int Init(Genius::TabFile& reader, int row, int col)
		{
			number1 = 1;
			if(reader.GetStringValue(row, col).length() > 0)
				number1 = reader.GetIntValue(row, col++);

			number2 = 2;
			if(reader.GetStringValue(row, col).length() > 0)
				number2 = reader.GetFloatValue(row, col++);

			number3 = 3;
			if(reader.GetStringValue(row, col).length() > 0)
				number3 = reader.GetDoubleValue(row, col++);

			number4 = 4;
			if(reader.GetStringValue(row, col).length() > 0)
				number4 = reader.GetLongValue(row, col++);

			number5 = false;
			if(reader.GetStringValue(row, col).length() > 0)
				number5 = reader.GetBoolValue(row, col++);

			filePath = "";
			if(reader.GetStringValue(row, col).length() > 0)
				filePath = reader.GetStringValue(row, col++);

			for(int i=0; i<3; i++)
				number6[i] = 6;
			vector<string> number6Array = reader.Split(reader.GetStringValue(row, col++), cfg::BaseConfig::Separator);
			int number6Count = number6Array.size();
			for(int i=0; i<3; i++)
			{
				if(i < number6Count)
					number6[i] = reader.ToInt(number6Array[i]);
				else
					number6[i] = 6;
			}

			for(int i=0; i<3; i++)
				number7[i] = 7;
			vector<string> number7Array = reader.Split(reader.GetStringValue(row, col++), cfg::BaseConfig::Separator);
			int number7Count = number7Array.size();
			for(int i=0; i<3; i++)
			{
				if(i < number7Count)
					number7[i] = reader.ToFloat(number7Array[i]);
				else
					number7[i] = 7;
			}

			for(int i=0; i<3; i++)
				number8[i] = "lolol";
			vector<string> number8Array = reader.Split(reader.GetStringValue(row, col++), cfg::BaseConfig::Separator);
			int number8Count = number8Array.size();
			for(int i=0; i<3; i++)
			{
				if(i < number8Count)
					number8[i] = reader.ToString(number8Array[i]);
				else
					number8[i] = "lolol";
			}

			return col;
		}
	};
	IMPL_CONFIG_CREATE(anim_cfg)
};