#ifndef _TAB_FILE_H_
#define _TAB_FILE_H_

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#define LINE_MAX_READ_LENTH 128

namespace Genius
{
	class TabFile
	{
	public:
		TabFile(){};
		~TabFile() {};

	public:
		int													GetIntValue(int row_index, int col_index);
		float													GetFloatValue(int row_index, int col_index);
		float													GetDoubleValue(int row_index, int col_index);
		float													GetLongValue(int row_index, int col_index);
		bool													GetBoolValue(int row_index, int col_index);
		std::string&										GetStringValue(int row_index, int col_index);

		int													ToInt(std::string& str);
		float													ToFloat(std::string& str);
		float													ToDouble(std::string& str);
		float													ToLong(std::string& str);
		bool													ToBool(std::string& str);
		std::string&										ToString(std::string& str);

	public:
		bool													LoadFile(const std::string& FileName);
		int													GetRowCount();
		int													GetColCount();
		std::vector<std::string>					Split(std::string& str, std::string& split_code);

	private:
		std::vector<std::string>					SplitRow(std::string& str);
		std::vector<std::string>					SplitCol(std::string& str);
		

	private:
		std::vector<std::vector<std::string>>				m_file_data;
		int													m_max_row_count;
		int													m_max_col_count;
	};

}

#endif
