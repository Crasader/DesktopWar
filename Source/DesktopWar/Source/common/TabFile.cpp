
#include "TabFile.h"
#include <cstdlib>
#include <fstream>
#include <iterator>

using namespace std;
using namespace Genius;


bool TabFile::LoadFile(const string& FileName)
{
	if (FileName[0] == 0)
		return false;

	string	m_InputData;
	m_InputData.clear();

	ifstream	m_InputFile;

	m_InputFile.open(FileName);
	copy(istreambuf_iterator<char>(m_InputFile), istreambuf_iterator<char>(), back_inserter(m_InputData));
	m_InputFile.close();

	vector<string> row_data = SplitRow(m_InputData);

	int row_count = row_data.size();
	
	for (int i = 0; i < row_count; i++)
	{
		vector<string> col_data = SplitCol(row_data[i]);
		if (i == 0)
		{
			m_max_col_count = col_data.size();
			continue;
		}
		if (col_data.size() == m_max_col_count)
			m_file_data.push_back(col_data);
	}

	m_max_row_count = m_file_data.size();

	return true;
}

vector<string> TabFile::Split(string& str, string& split_code)
{
	int current;
	int next = -1;
	vector<string> strs;
	do
	{
		current = next + 1;
		next = str.find_first_of(split_code, current);
		strs.push_back(str.substr(current, next - current));
	} while (next != string::npos);
	return strs;
}

vector<string> TabFile::SplitRow(string& str)
{
	string splict_row = "\n";
	return Split(str, splict_row);
}

vector<string> TabFile::SplitCol(string& str)
{
	string splict_row = "\t";
	return Split(str, splict_row);
}

int TabFile::GetIntValue(int row_index, int col_index)
{
	return (int)atoi(m_file_data[row_index][col_index].size() > 0 ? m_file_data[row_index][col_index].c_str() : "0");
}

float TabFile::GetFloatValue(int row_index, int col_index)
{
	return (float)atof(m_file_data[row_index][col_index].size() > 0 ? m_file_data[row_index][col_index].c_str() : "0");
}

bool TabFile::GetBoolValue(int row_index, int col_index)
{
	return atoi(m_file_data[row_index][col_index].size() > 0 ? m_file_data[row_index][col_index].c_str() : "0") > 0 ? true : false;
}

string TabFile::GetStringValue(int row_index, int col_index)
{
	return m_file_data[row_index][col_index];
}

int TabFile::GetMaxRowCount()
{
	return m_max_row_count;
}

int TabFile::GetMaxColCount()
{
	return m_max_col_count;
}


