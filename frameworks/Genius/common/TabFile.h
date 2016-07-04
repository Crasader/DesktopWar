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
		std::string											GetStringValue(int row_index, int col_index);

		int													ToInt(string& str);
		float													ToFloat(string& str);
		float													ToDouble(string& str);
		float													ToLong(string& str);
		bool													ToBool(string& str);
		string												ToString(string& str);

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
