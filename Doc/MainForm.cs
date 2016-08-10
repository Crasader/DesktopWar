using System;
using System.IO;
using System.Xml;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using CSOpenXmlExcelToCS;
using CSOpenXmlExcelToJava;
using CSOpenXmlExcelToXML;
using CSOpenXmlExcelToCheckExcel;
using Newtonsoft.Json;
using Newtonsoft.Json.Converters;

namespace AssignmentTableTool
{
	public partial class MainForm : Form
	{
		private string ExcelFileName = "";
		private string JsonFileName = "";

		private const string TabFolderName = "Tab(client)";
		private const string JsonFolderName = "Tab(client)";

		public MainForm()
		{
			InitializeComponent();
		}

		#region Broswer Excel File
		/// <summary>
		///  Open an dialog to let users select Excel file
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void ExcelFileBtn_Click(object sender, EventArgs e)
		{
			// Initializes a OpenFileDialog instance 
			using (OpenFileDialog openfileDialog = new OpenFileDialog())
			{
				openfileDialog.RestoreDirectory = true;
				openfileDialog.Filter = "Excel files(*.xlsx)|*.xlsx";

				if (openfileDialog.ShowDialog() == DialogResult.OK)
				{
					ExcelFileTextBox.Text = openfileDialog.FileName;
				}
				ExcelFileName = Path.GetFileNameWithoutExtension(openfileDialog.FileName);
			}
		}

		#endregion

		#region Convert Excel To Json or Tab

		/// <summary>
		///  Convert Excel file to XML format
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		static private string ExcelConvertToXML(string excelName)
		{
			//string excelName = ExcelFileTextBox.Text;

			if (string.IsNullOrEmpty(excelName) || !File.Exists(excelName))
			{
				MessageBox.Show("The " + excelName + " file is invalid! Please select a valid file.");
				return null;
			}

			try
			{
				//check excel file
				string result = new CheckExcelFile().ReadExcelFile(excelName);
				if (!result.Equals(""))
				{
					MessageBox.Show(result);
					return null;
				}

                string xmlFormatstring = new XlsxToXML().GetXML(excelName);
                if (string.IsNullOrEmpty(xmlFormatstring))
                {
                    MessageBox.Show("The content of " + excelName + " file is Empty!");
                    return null;
                }

				return xmlFormatstring;
			}
			catch (Exception ex)
			{
				MessageBox.Show(excelName + " has error! The error message is: " + ex.Message);
				return null;
			}
		}

		/// <summary>
		///  Convert XML file to Json format
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		static private string XMLConvertToJson(string str)
		{
			try
			{
				XmlDocument doc = new XmlDocument();
				doc.LoadXml(str);

				return JsonConvert.SerializeXmlNode(doc);
			}
			catch (Exception ex)
			{
				MessageBox.Show("Error occurs! The error message is: " + ex.Message);
				return null;
			}
		}

		/// <summary>
		///  Format Json string
		/// </summary>
		private static string FormatJsonString(string str)
		{
			JsonSerializer serializer = new JsonSerializer();
			TextReader tr = new StringReader(str);
			JsonTextReader jtr = new JsonTextReader(tr);
			object obj = serializer.Deserialize(jtr);
			if (obj != null)
			{
				StringWriter textWriter = new StringWriter();
				JsonTextWriter jsonWriter = new JsonTextWriter(textWriter)
				{
					Formatting = Newtonsoft.Json.Formatting.Indented,
					Indentation = 1,
					IndentChar = '	'
				};
				serializer.Serialize(jsonWriter, obj);
				return textWriter.ToString();
			}
			else
			{
				return str;
			}
		}

		/// <summary>
		///  Convert Excel file to tab format
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		static private string ExcelConvertToTab(string excelName)
		{
			if (string.IsNullOrEmpty(excelName) || !File.Exists(excelName))
			{
				MessageBox.Show("The " + excelName + " file is invalid! Please select a valid file.");
				return null;
			}

			try
			{
				//check excel file
				string result = new CheckExcelFile().ReadExcelFile(excelName);
				if (!result.Equals(""))
				{
					MessageBox.Show(result);
					return null;
				}

				string xmlFormatstring = new XlsxToTab().ReadExcelFile(excelName);
				if (string.IsNullOrEmpty(xmlFormatstring))
				{
					MessageBox.Show("The content of " + excelName + " file is Empty!");
					return null;
				}

				return xmlFormatstring;
			}
			catch (Exception ex)
			{
				MessageBox.Show(excelName + " has error! The error message is: " + ex.Message);
				return null;
			}
		}

		/// <summary>
		///  Convert Excel file to Json format
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void ConvertToJsonBtn_Click(object sender, EventArgs e)
		{
			string outputPathTab = System.IO.Path.GetDirectoryName(ExcelFileTextBox.Text );
			if (!Directory.Exists(outputPathTab))
				Directory.CreateDirectory(outputPathTab);

			//CreateTabFile(ExcelFileTextBox.Text, outputPathTab, ".tab.txt");

			/*string outputPathJson = System.IO.Path.GetDirectoryName(ExcelFileTextBox.Text) + @"\Json(server)";
			if (!Directory.Exists(outputPathJson))
				Directory.CreateDirectory(outputPathJson);

			CreateJsonFile(ExcelFileTextBox.Text, outputPathJson, ".json.txt");*/

			CreateJavaScriptFile(ExcelFileTextBox.Text, outputPathTab);
		}

		#endregion

		#region Broswer Json File

		/// <summary>
		///  Open an dialog to let users select Json file
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void JsonFileBtn_Click(object sender, EventArgs e)
		{
			// Initializes a OpenFileDialog instance 
			using (OpenFileDialog openfileDialog = new OpenFileDialog())
			{
				openfileDialog.RestoreDirectory = true;
				openfileDialog.Filter = "Json files(*.json.txt)|*.json.txt";

				if (openfileDialog.ShowDialog() == DialogResult.OK)
				{
					JsonFileTextBox.Text = openfileDialog.FileName;
				}
				JsonFileName = Path.GetFileNameWithoutExtension(openfileDialog.FileName);
			}
		}

		#endregion

		#region Convert Json To Excel

		private string strPath = "";

		/// <summary>
		///  Convert Json file to XML format
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private bool JsonConvertToXML()
		{
			string jsonName = JsonFileTextBox.Text;
			strPath = jsonName + ".xml";

			if (string.IsNullOrEmpty(jsonName) || !File.Exists(jsonName))
			{
				MessageBox.Show("The Json file is invalid! Please select a valid file.");
				return false;
			}

			try
			{
				StreamReader streamreader = new StreamReader(jsonName);
				String jsonFormatstring = "";
				String content = "";

				// Add ExcelFileName and SheetName To Json
				jsonFormatstring += "{\"" + JsonFileName.Substring(0, JsonFileName.Length - 5) + "\":{\"Sheet1\":";

				while (null != content)
				{
					content = streamreader.ReadLine();
					jsonFormatstring += content;
				}

				jsonFormatstring += "}}";

				if (string.IsNullOrEmpty(jsonFormatstring))
				{
					MessageBox.Show("The content of Json file is Empty!");
					return false;
				}

				string xmlNode = JsonConvert.DeserializeXmlNode(jsonFormatstring).OuterXml;

				//xml file
				StreamWriter streamwriter = new StreamWriter(strPath, true);
				streamwriter.WriteLine(xmlNode);
				streamwriter.Flush();
				streamwriter.Close();

				//file attributes hidden
				FileInfo file = new FileInfo(strPath);
				file.Attributes = FileAttributes.Hidden;

				return true;
			}
			catch (Exception ex)
			{
				MessageBox.Show("Error occurs! The error message is: " + ex.Message);
				return false;
			}
		}

		/// <summary>
		///  Convert Json file to XML format
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void XMLConvertToExcel()
		{
			try
			{
				MSDN.Sample.XMLToExcel.OpenXMLOffice objTest = new MSDN.Sample.XMLToExcel.OpenXMLOffice();

				// Initializes a SaveFileDialog instance 
				using (SaveFileDialog savefiledialog = new SaveFileDialog())
				{
					savefiledialog.RestoreDirectory = true;
					savefiledialog.DefaultExt = ".xlsx";
					savefiledialog.Filter = "All files(*.xlsx)|*.xlsx";
					if (savefiledialog.ShowDialog() == DialogResult.OK)
					{
						objTest.XMLToExcel(strPath, savefiledialog.FileName);
					}
				}
			}
			catch (Exception ex)
			{
				MessageBox.Show("Error occurs! The error message is: " + ex.Message);
				return;
			}
		}

		/// <summary>
		///  Convert Json file to Excel format
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void ConvertToExcel_Click(object sender, EventArgs e)
		{
			try
			{
				if (JsonConvertToXML())
				{
					XMLConvertToExcel();
					File.Delete(strPath);
				}
			}
			catch (Exception ex)
			{
				MessageBox.Show("Error occurs! The error message is: " + ex.Message);
				return;
			}
		}

		#endregion

		#region Convert Excel To CS

		private void ConvertToCSBtn_Click(object sender, EventArgs e)
		{
			try
			{
				//CreateCSFile(ExcelFileTextBox.Text, System.IO.Path.GetDirectoryName(ExcelFileTextBox.Text), ".cs");
				CreateCPPFile(ExcelFileTextBox.Text, System.IO.Path.GetDirectoryName(ExcelFileTextBox.Text));
			}
			catch (Exception ex)
			{
				MessageBox.Show(ExcelFileTextBox.Text + " has error! The error message is: " + ex.Message);
			}
		}

		#endregion

		#region Convert Excel To Java

		private void ConvertToJavaBtn_Click(object sender, EventArgs e)
		{
			CreateJavaFile(ExcelFileTextBox.Text, ".java");
		}

		#endregion

		#region Convert All Excel To Json, CS, Java

		private void ExcelFolderBtn_Click(object sender, EventArgs e)
		{
			ExcelFolderTextBox.Text = GetFolderPath("选择策划数据源Excel路径地址");
		}

		private void ConvertAllExcelToJsonBtn_Click(object sender, EventArgs e)
		{
			if (ExcelFolderTextBox.Text == "")
			{
				//MessageBox.Show("");
				return;
			}

			string path = GetFolderPath("选择保存Json文件的路径");

			// to tab
			string outputPathTab = path;
			if (!Directory.Exists(outputPathTab))
				Directory.CreateDirectory(outputPathTab);

			CreateAllTabFile(ExcelFolderTextBox.Text, outputPathTab);

			// to json
			/*string outputPathJson = path + @"\\Json(server)";
			if (!Directory.Exists(outputPathJson))
				Directory.CreateDirectory(outputPathJson);
                
			CreateAllJsonFile(ExcelFolderTextBox.Text, outputPathJson);*/
		}

		private void ConvertAllExcelToCsBtn_Click(object sender, EventArgs e)
		{
			if (ExcelFolderTextBox.Text == "")
			{
				//MessageBox.Show("");
				return;
			}

			string path = GetFolderPath("选择保存CS文件的路径");

			DirectoryInfo mydir = new DirectoryInfo(ExcelFolderTextBox.Text);
			foreach (FileSystemInfo fsi in mydir.GetFiles("*.xlsx", SearchOption.AllDirectories))
			{
				FileInfo fileInfo = (FileInfo)fsi;
				try
				{
					string Extension = System.IO.Path.GetExtension(fileInfo.FullName);
					if (Extension.Equals(".xlsx"))
					{
						//CreateCSFile(fileInfo.FullName, path, ".cs");
						CreateCPPFile(fileInfo.FullName, path);
					}
				}
				catch (Exception ex)
				{
					MessageBox.Show(fileInfo.FullName + " has error! The error message is: " + ex.Message);
				}
			}
		}

		private void ConvertAllExcelToJavaBtn_Click(object sender, EventArgs e)
		{
			if (ExcelFolderTextBox.Text == "")
			{
				//MessageBox.Show("");
				return;
			}

			string path = GetFolderPath("选择保存Java文件的路径");

			DirectoryInfo mydir = new DirectoryInfo(ExcelFolderTextBox.Text);
			foreach (FileSystemInfo fsi in mydir.GetFiles("*.xlsx", SearchOption.AllDirectories))
			{
				FileInfo fileInfo = (FileInfo)fsi;
				string Extension = System.IO.Path.GetExtension(fileInfo.FullName);
				if (Extension.Equals(".xlsx"))
				{
					string javaFile = "";
					try
					{
						javaFile += "package com.mad.base.template;" + "\n\n";
						javaFile += "import java.util.Arrays;" + "\n";
						javaFile += "import java.util.List;" + "\n\n";
						javaFile += "import net.sf.json.JSONArray;" + "\n\n";
						javaFile += "import com.mad.boom.data.template.Template;" + "\n";
						javaFile += "import com.mad.boom.data.template.TemplateId;" + "\n\n";

						javaFile += "@Template" + "\n";
						javaFile += "public class " + System.IO.Path.GetFileNameWithoutExtension(fileInfo.FullName) + " {\n\n";
						javaFile += "\tprivate String title;" + "\n";

						javaFile += new XlsxToJava().ReadExcelFile(fileInfo.FullName, System.IO.Path.GetFileNameWithoutExtension(fileInfo.FullName));

						javaFile += "}" + "\n";

						//java file
						StreamWriter streamwriter = new StreamWriter(path + @"\" + System.IO.Path.GetFileNameWithoutExtension(fileInfo.FullName) + ".java", false);
						streamwriter.Write(javaFile);
						streamwriter.Flush();
						streamwriter.Close();
					}
					catch (Exception ex)
					{
						MessageBox.Show(fileInfo.FullName + " has error! The error message is: " + ex.Message);
					}
				}
			}
		}

		#endregion

		#region GetFolderPath

		private string GetFolderPath(string title)
		{
			string path = "";
			using (FolderBrowserDialog folderBrowserDialog = new FolderBrowserDialog())
			{
				folderBrowserDialog.Description = title;
				folderBrowserDialog.ShowNewFolderButton = false;

				if (ExcelFolderTextBox.Text != "")
				{
					folderBrowserDialog.SelectedPath = ExcelFolderTextBox.Text;
				}
				else
				{
					folderBrowserDialog.RootFolder = Environment.SpecialFolder.MyComputer;
				}

				if (folderBrowserDialog.ShowDialog() == DialogResult.OK)
				{
					string folderPath = folderBrowserDialog.SelectedPath;
					if (folderPath != "")
					{
						path = folderPath;
					}
				}
			}
			return path;
		}

		#endregion

		#region CreateJsonFile

		public static void CreateAllJsonFile(string strSrc, string strPath)
		{
			DirectoryInfo mydir = new DirectoryInfo(strSrc);
			foreach (FileSystemInfo fsi in mydir.GetFiles("*.xlsx", SearchOption.AllDirectories))
			{
				FileInfo fileInfo = (FileInfo)fsi;
				try
				{
					string Extension = System.IO.Path.GetExtension(fileInfo.FullName);
					if (Extension.Equals(".xlsx"))
					{
						CreateJsonFile(fileInfo.FullName, strPath, ".json.txt");
					}
				}
				catch (Exception ex)
				{
					MessageBox.Show(fileInfo.FullName + " has error! The error message is: " + ex.Message);
					continue;
				}
			}
		}

		public static void CreateJsonFile(string strSrc, string strPath, string strExtension)
		{
			string strJson = "";
			string strXml = ExcelConvertToXML(strSrc);
			
			if (null == strXml)
			{
				//MessageBox.Show("The content of Excel file is Empty!");
				return;
			}
			strJson = XMLConvertToJson(strXml);

			// remove ExcelFileName and SheetName from json.txt
			string[] index = strJson.Split('[');
			int len = index[0].Length;
			strJson = strJson.Substring(len, strJson.Length - len - 2);

			if (null == strJson)
			{
				//MessageBox.Show("The content of Excel file is Empty!");
				return;
			}

			strJson = FormatJsonString(strJson);

			string fileName = System.IO.Path.GetFileNameWithoutExtension(strSrc);
			StreamWriter streamwriter = new StreamWriter(strPath + @"\" + fileName + strExtension, false);
			streamwriter.Write(strJson);
			streamwriter.Flush();
			streamwriter.Close();

		}

		

		#endregion

		#region CreateTabFile
		public static void CreateAllTabFile(string strSrc, string strPath)
		{
			DirectoryInfo mydir = new DirectoryInfo(strSrc);
			foreach (FileSystemInfo fsi in mydir.GetFiles("*.xlsx", SearchOption.AllDirectories))
			{
				FileInfo fileInfo = (FileInfo)fsi;
				try
				{
					string Extension = System.IO.Path.GetExtension(fileInfo.FullName);
					if (Extension.Equals(".xlsx"))
					{
						CreateTabFile(fileInfo.FullName, strPath, ".tab.txt");
					}
				}
				catch (Exception ex)
				{
					MessageBox.Show(fileInfo.FullName + " has error! The error message is: " + ex.Message);
					continue;
				}
			}
		}

		public static void CreateTabFile(string strSrc, string strPath, string strExtension)
		{
			string strJson = "";
			string strXml = ExcelConvertToTab(strSrc);
			strJson = strXml;
			if (null == strXml)
			{
				//MessageBox.Show("The content of Excel file is Empty!");
				return;
			}

			StreamWriter streamwriter = new StreamWriter(strPath + @"\" + System.IO.Path.GetFileNameWithoutExtension(strSrc) + strExtension, false);
			streamwriter.Write(strJson);
			streamwriter.Flush();
			streamwriter.Close();

		}

		#endregion

		#region js
		public static void CreateAllJavaScriptFile(string strSrc, string strPath)
		{
			DirectoryInfo mydir = new DirectoryInfo(strSrc);
			foreach (FileSystemInfo fsi in mydir.GetFiles("*.xlsx", SearchOption.AllDirectories))
			{
				FileInfo fileInfo = (FileInfo)fsi;
				try
				{
					string Extension = System.IO.Path.GetExtension(fileInfo.FullName);
					if (Extension.Equals(".xlsx"))
					{
						CreateJavaScriptFile(fileInfo.FullName, strPath);
					}
				}
				catch (Exception ex)
				{
					MessageBox.Show(fileInfo.FullName + " has error! The error message is: " + ex.Message);
					continue;
				}
			}
		}

		public static void CreateJavaScriptFile(string strSrc, string strPath)
		{
			string fileName = System.IO.Path.GetFileNameWithoutExtension(strSrc);

			StringBuilder jsStrBuilder = new StringBuilder();
			jsStrBuilder.Append("\n// This is a javascript file generated from " + fileName + ".xlsx\n");
			jsStrBuilder.Append("Config." + fileName + "={};\n\n");
			jsStrBuilder.Append(new XlsxToJS().ReadExcelFile(strSrc, fileName));

			StreamWriter streamwriter = new StreamWriter(strPath + @"\" + fileName + ".js", false);
			streamwriter.Write(jsStrBuilder.ToString());
			streamwriter.Flush();
			streamwriter.Close();
		}
#endregion
		#region CreateCSFile

		private void CreateCSFile(string strSrc, string strPath, string strExtension)
		{
			string csFile = "";

			csFile += "using System;" + "\n";
			csFile += "using System.Collections.Generic;" + "\n";
			csFile += "using Newtonsoft.Json;" + "\n";
			csFile += "using Newtonsoft.Json.Linq;" + "\n\n";

			csFile += "namespace Mad" + "\n";
			csFile += "{" + "\n";
			csFile += "\tpublic class " + System.IO.Path.GetFileNameWithoutExtension(strSrc) + "_Tbl : BaseConfig" + "\n";
			csFile += "\t" + "{" + "\n";

			csFile += "\t\tpublic " + System.IO.Path.GetFileNameWithoutExtension(strSrc) + "_Tbl()" + "\n\t\t{" + "\n\n\t\t}" + "\n\n";

			csFile += new XlsxToCS().ReadExcelFile(strSrc);

			csFile += "\t}" + "\n";
			csFile += "}";

			StreamWriter streamwriter = new StreamWriter(strPath + @"\" + System.IO.Path.GetFileNameWithoutExtension(strSrc) + "_Tbl" + strExtension, false);
			streamwriter.Write(csFile);
			streamwriter.Flush();
			streamwriter.Close();

			//// Initializes a SaveFileDialog instance 
			//using (SaveFileDialog savefiledialog = new SaveFileDialog())
			//{
			//    savefiledialog.RestoreDirectory = true;
			//    savefiledialog.DefaultExt = ".cs";
			//    savefiledialog.Filter = "All files(*.cs)|*.cs";
			//    if (savefiledialog.ShowDialog() == DialogResult.OK)
			//    {
			//        //cs file
			//        StreamWriter streamwriter = new StreamWriter(savefiledialog.FileName, true);
			//        streamwriter.Write(csFile);
			//        streamwriter.Flush();
			//        streamwriter.Close();
			//    }
			//}
		}

		#endregion

		#region CreateJavaFile

		private void CreateJavaFile(string strPath, string strExtension)
		{
			string javaFile = "";
			try
			{
				javaFile += "package com.mad.base.template;" + "\n\n";
				javaFile += "import java.util.Arrays;" + "\n";
				javaFile += "import java.util.List;" + "\n\n";
				javaFile += "import net.sf.json.JSONArray;" + "\n\n";
				javaFile += "import com.mad.boom.data.template.Template;" + "\n";
				javaFile += "import com.mad.boom.data.template.TemplateId;" + "\n\n";

				javaFile += "@Template" + "\n";
				javaFile += "public class " + ExcelFileName + " {\n\n";
				javaFile += "\tprivate String title;" + "\n";

				javaFile += new XlsxToJava().ReadExcelFile(ExcelFileTextBox.Text, ExcelFileName);

				javaFile += "}" + "\n";

				StreamWriter streamwriter = new StreamWriter(System.IO.Path.GetDirectoryName(strPath) + @"\" + System.IO.Path.GetFileNameWithoutExtension(strPath) + strExtension, false);
				streamwriter.Write(javaFile);
				streamwriter.Flush();
				streamwriter.Close();
			}
			catch (Exception ex)
			{
				MessageBox.Show("Error occurs! The error message is: " + ex.Message);
			}

			//// Initializes a SaveFileDialog instance 
			//using (SaveFileDialog savefiledialog = new SaveFileDialog())
			//{
			//    savefiledialog.RestoreDirectory = true;
			//    savefiledialog.DefaultExt = ".java";
			//    savefiledialog.Filter = "All files(*.java)|*.java";
			//    if (savefiledialog.ShowDialog() == DialogResult.OK)
			//    {
			//        //cs file
			//        StreamWriter streamwriter = new StreamWriter(savefiledialog.FileName, true);
			//        streamwriter.Write(javaFile);
			//        streamwriter.Flush();
			//        streamwriter.Close();
			//    }
			//}
		}

		#endregion


		private void CreateCPPFile(string strSrc, string strPath)
		{
			string fileName = System.IO.Path.GetFileNameWithoutExtension(strSrc) + "_cfg";

			string hppFile = "";

			hppFile += "\n#pragma once\n\n";

			hppFile += "#include \"../BaseConfig.h\"\n";

			hppFile += "\nnamespace cfg\n";
			hppFile += "{\n";
			hppFile += "\tclass " + fileName + " : public BaseConfig\n";
			hppFile += "\t{\n";
			hppFile += "\tpublic:\n\n";
			hppFile += "\t\tDECLARE_CONFIG_CREATE(" + fileName + ")\n\n";
			hppFile += "\t\tvirtual int Init(Genius::TabFile& reader, int row, int col);\n\n";
			string hppString = "";
			string cppString = "";
			new XlsxToCPP().ReadExcelFile(strSrc, fileName, out hppString, out cppString);
			hppFile += hppString;
			hppFile += "\t};\n};";

			StreamWriter streamwriter = new StreamWriter(strPath + @"\" + fileName + ".hpp", false);
			streamwriter.Write(hppFile);
			streamwriter.Flush();
			streamwriter.Close();

			// cpp
			string cppFile = "";

			cppFile += "#include \"" + fileName + ".hpp\"\n";
			cppFile += "\nusing namespace cfg;\n\n";

			cppFile += "IMPL_CONFIG_CREATE(" + fileName + ");\n";

			cppFile += cppString;

			StreamWriter cppwriter = new StreamWriter(strPath + @"\" + fileName + ".cpp", false);
			cppwriter.Write(cppFile);
			cppwriter.Flush();
			cppwriter.Close();
		}


	}
}
