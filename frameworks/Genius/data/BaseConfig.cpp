
#include "BaseConfig.h"

using namespace std;

using namespace cfg;
using namespace Genius;

string BaseConfig::Separator = ",";

int BaseConfig::Init(Genius::TabFile& reader, int row, int col)
{
	auto idStr = reader.GetStringValue(row, col);
	id = reader.ToInt(idStr);

	return ++col;
}

