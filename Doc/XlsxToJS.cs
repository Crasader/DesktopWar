/****************************** Module Header ******************************\
* Module Name:  ConvertExcelToTab.cs
* Project:      
* 
\***************************************************************************/


using System;
using System.Collections.Generic;
using System.Data;
using System.IO;
using System.Linq;
using System.Text.RegularExpressions;
using DocumentFormat.OpenXml.Packaging;
using DocumentFormat.OpenXml.Spreadsheet;

using System.Data.OleDb;
using System.Data.SqlTypes;
//using Microsoft.Office.Core;


namespace CSOpenXmlExcelToXML
{
	public class XlsxToJS
	{
		public string ConvertExcelFile(string filename)
		{

			System.Text.StringBuilder resultFile = new System.Text.StringBuilder();

			var conn = new OleDbConnection();
			conn.ConnectionString = String.Format(@"Provider=Microsoft.ACE.OLEDB.12.0;" +
				@"Data Source={0}" + ";Extended Properties=\"Excel 12.0 Xml;HDR=No;IMEX=1\"", filename);
			conn.Open();
			DataTable sheetTb = conn.GetOleDbSchemaTable(OleDbSchemaGuid.Tables, null);
			foreach (DataRow sheet in sheetTb.Rows)
			{
				string tableName = sheet["TABLE_NAME"].ToString();

				string sql = String.Format("select * from [{0}]", tableName);
				OleDbDataAdapter da = new OleDbDataAdapter(sql, conn);

				var ds = new DataSet();
				da.Fill(ds);

				var tb1 = ds.Tables[0];

				if (tb1.Rows.Count == 0)
				{
					continue; // 空表
				}
				if (tb1.Rows.Count == 1 && tb1.Columns.Count == 1)
				{
					if (tb1.Rows[0][0] == DBNull.Value)
					{
						continue; // 空表
					}
				}

				int[] colMaxLen = new int[tb1.Columns.Count];
				string defaultText = "";
				foreach (DataRow row in tb1.Rows)
				{
					for (int j = 0; j < tb1.Columns.Count; ++j)
					{
						DataColumn col = tb1.Columns[j];
						string cellText = row[j].ToString();

						if (cellText == null)
							cellText = defaultText;
						if (j + 1 == tb1.Columns.Count)
							resultFile.Append(cellText);
						else
						{
							resultFile.Append(cellText);
							resultFile.Append("\t");
						}
						
					}
					resultFile.Append("\n");

				}
			}
			conn.Close();

			return resultFile.ToString();
		}

		public string ReadExcelFile(string filename, string className)
		{
			// Initialize an instance of DataTable
			DataTable dt = new DataTable();
			System.Text.StringBuilder resultFile = new System.Text.StringBuilder();

			try
			{
				// Use SpreadSheetDocument class of Open XML SDK to open excel file
				using (SpreadsheetDocument spreadsheetDocument = SpreadsheetDocument.Open(filename, false))
				{
					// Get Workbook Part of Spread Sheet Document
					WorkbookPart workbookPart = spreadsheetDocument.WorkbookPart;

					// Get all sheets in spread sheet document 
					IEnumerable<Sheet> sheetcollection = spreadsheetDocument.WorkbookPart.Workbook.GetFirstChild<Sheets>().Elements<Sheet>();

					// Get relationship Id
					string relationshipId = sheetcollection.First().Id.Value;

					// Set DataTable's TableName
					dt.TableName = sheetcollection.First().Name;

					// Get sheet1 Part of Spread Sheet Document
					WorksheetPart worksheetPart = (WorksheetPart)spreadsheetDocument.WorkbookPart.GetPartById(relationshipId);

					// Get Data in Excel file
					SheetData sheetData = worksheetPart.Worksheet.Elements<SheetData>().First();
					IEnumerable<Row> rowcollection = sheetData.Descendants<Row>();

					if (rowcollection.Count() == 0)
					{
						return null;
					}

					// Add columns
					foreach (Cell cell in rowcollection.ElementAt(0))
					{
						dt.Columns.Add(GetValueOfCell(spreadsheetDocument, cell, false));
					}

					int columnsCount = dt.Columns.Count;
					bool[] isBoolean = new bool[columnsCount];

					// is bool
					foreach (Cell cell in rowcollection.ElementAt(3).Descendants<Cell>())
					{
						int cellColumnIndex = GetColumnIndex(GetColumnName(cell.CellReference));
						string cellInfo = GetValueOfCell(spreadsheetDocument, cell, false);
						if (cellInfo.Equals("bool"))
							isBoolean[cellColumnIndex] = true;
						else
							isBoolean[cellColumnIndex] = false;
					}

					// Add rows into DataTable, because cell in original table may be empty 
					foreach (Row row in rowcollection)
					{
						DataRow tempRow = dt.NewRow();
						int columnIndex = 0;
						foreach (Cell cell in row.Descendants<Cell>())
						{
							// Get Cell Column Index
							int cellColumnIndex = GetColumnIndex(GetColumnName(cell.CellReference));

							if (columnIndex < cellColumnIndex)
							{
								do
								{
									tempRow[columnIndex] = string.Empty;
									columnIndex++;
								}
								while (columnIndex < cellColumnIndex);
							}

							string cellValue = GetValueOfCell(spreadsheetDocument, cell, isBoolean[cellColumnIndex]);
							tempRow[columnIndex] = cellValue;
							columnIndex++;
						}

						// Add the row to DataTable
						dt.Rows.Add(tempRow);
					}
					// Here remove header row
					dt.Rows.RemoveAt(0);



					// Get variableName array
					// the first row is variableName
					string[] variableName = new string[columnsCount];
					foreach (Cell cell in rowcollection.First().Descendants<Cell>())
					{
						string a = GetColumnName(cell.CellReference);
						int cellColumnIndex = GetColumnIndex(GetColumnName(cell.CellReference));
						variableName[cellColumnIndex] = GetValueOfCell(spreadsheetDocument, cell, isBoolean[cellColumnIndex]);
					}

					// Add variableName Info To Cpp
					// the third row is variableType
					string[] variableLength = new string[columnsCount];
					string[] variableType = new string[columnsCount];
					foreach (Cell cell in rowcollection.ElementAt(3).Descendants<Cell>())
					{
						int cellColumnIndex = GetColumnIndex(GetColumnName(cell.CellReference));

						string cellInfo = GetValueOfCell(spreadsheetDocument, cell, isBoolean[cellColumnIndex]);
						variableLength[cellColumnIndex] = "";
						variableType[cellColumnIndex] = cellInfo;

						//array
						if (cellInfo.EndsWith("]"))
						{
							int startIndex = cellInfo.IndexOf('[');
							variableLength[cellColumnIndex] = cellInfo.Substring(startIndex + 1, cellInfo.Length - startIndex - 2);
							variableType[cellColumnIndex] = cellInfo.Substring(0, startIndex);
						}

					}

					// Get variableDefaultValue array
					// the fourth row is variableDefaultValue
					string[] variableDefaultValue = new string[columnsCount];
					foreach (Cell cell in rowcollection.ElementAt(4).Descendants<Cell>())
					{
						int cellColumnIndex = GetColumnIndex(GetColumnName(cell.CellReference));
						variableDefaultValue[cellColumnIndex] = GetValueOfCell(spreadsheetDocument, cell, isBoolean[cellColumnIndex]).Replace("\"","");
					}

					
					foreach (DataRow row in dt.Rows)
					{
						int id = 0;
						int.TryParse(row[1].ToString(), out id);
						if(id<=0)
							continue;

						System.Text.StringBuilder onePiece = new System.Text.StringBuilder();
						onePiece.Append("Config." + className + "['" + row[1].ToString() + "']={\n");
						for (int j = 0; j < columnsCount; ++j)
						{
							onePiece.Append("\t"+variableName[j]+":");
							string cellText = row[j].ToString();
							//cellText = cellText.Replace("\n", "\\n");
							if(cellText == string.Empty)
								cellText = variableDefaultValue[j];
							ParseValue(variableType[j], variableLength[j], cellText, ref cellText);
							onePiece.Append(cellText);
							if (j == columnsCount-1)
								onePiece.Append("\n");
							else
								onePiece.Append(",\n");
						}
						onePiece.Append("};\n\n");

						resultFile.Append(onePiece);
					}

				}
				return resultFile.ToString();
			}
			catch (IOException ex)
			{
				throw new IOException(ex.Message);
			}
		}

		void ParseValue(string type, string length, string text, ref string result)
		{
			if (length.Equals(""))
			{
				if (type.Equals("string"))
				{
					result = "'" + text + "'";
				}
			}
			else
			{
				if (type.Equals("int") || type.Equals("float") || type.Equals("double") || type.Equals("long") || type.Equals("bool"))
				{
					result = "[" + result + "]";
				}
				else if (type.Equals("string"))
				{
					result = result.Replace(",", "','");
					result = "['" + result + "']";
				}
			}

		}

		/// <summary>
		///  Get Value of Cell 
		/// </summary>
		/// <param name="spreadsheetdocument">SpreadSheet Document Object</param>
		/// <param name="cell">Cell Object</param>
		/// <returns>The Value in Cell</returns>
		private static string GetValueOfCell(SpreadsheetDocument spreadsheetdocument, Cell cell, bool isbool)
		{
			// Get value in Cell
			SharedStringTablePart sharedString = spreadsheetdocument.WorkbookPart.SharedStringTablePart;
			if (cell.CellValue == null)
			{
				return string.Empty;
			}

			string cellValue = cell.CellValue.InnerText;
			if (isbool)
			{
				if (cellValue.Equals("1"))
					cellValue = "true";
				else if (cellValue.Equals("0"))
					cellValue = "false";
			}
			// The condition that the Cell DataType is SharedString
			if (cell.DataType != null && cell.DataType.Value == CellValues.SharedString)
			{
				return sharedString.SharedStringTable.ChildElements[int.Parse(cellValue)].InnerText;
			}
			else
			{
				return cellValue;
			}
		}


		/// <summary>
		/// Get Column Name From given cell name
		/// </summary>
		/// <param name="cellReference">Cell Name(For example,A1)</param>
		/// <returns>Column Name(For example, A)</returns>
		private string GetColumnName(string cellReference)
		{
			// Create a regular expression to match the column name of cell
			Regex regex = new Regex("[A-Za-z]+");
			Match match = regex.Match(cellReference);
			return match.Value;
		}

		/// <summary>
		/// Get Index of Column from given column name
		/// </summary>
		/// <param name="columnName">Column Name(For Example,A or AA)</param>
		/// <returns>Column Index</returns>
		private int GetColumnIndex(string columnName)
		{
			int columnIndex = 0;
			int factor = 1;

			// From right to left
			for (int position = columnName.Length - 1; position >= 0; position--)
			{
				// For letters
				if (Char.IsLetter(columnName[position]))
				{
					columnIndex += factor * ((columnName[position] - 'A') + 1) - 1;
					factor *= 26;
				}
			}

			if ((columnName.Length - 1) >= 1)
			{
				//columnIndex += 1 + (columnName[columnName.Length - 2] - 'A');
				columnIndex += 1;
			}

			return columnIndex;
		}


	}
}
