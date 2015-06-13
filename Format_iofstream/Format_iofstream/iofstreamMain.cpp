#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	//打开文件并读取
	ifstream in("fun.txt");
	if (!in)
	{
		cerr << "无法打开文件" << endl;
		return -1;
	}
	string line;
	vector<string> functions;
	while (getline(in, line))
	{
		functions.push_back(line);
	}
	in.close();


	//提取有用信息并最终保存为vector<string>
	vector<string> functions_format;
	functions_format.resize(functions.size());
	for (int i = 0; i < functions.size(); i++)
	{
		//判断返回类型
		auto pos_void = functions[i].find("void");
		if (pos_void == string::npos)
		{
			functions_format[i] = "USFUNCNR";
		}
		else
		{
			functions_format[i] = "USFUNCVR";
		}
		//提取函数名
		auto pos_bracket_l = functions[i].find('(');
		auto pos_bracket_r = functions[i].find(')');
		string str1 = functions[i].substr(0, pos_bracket_l);
		string str2 = functions[i].substr(pos_bracket_l+1,pos_bracket_r-pos_bracket_l-1);
		int pos_funname_r = -1, pos_funname_l = -1;
		for (int j = str1.size()-1; j >=0 ; j--)
		{
			if ((pos_funname_r == -1) && (str1[j] != ' '))
			{
				pos_funname_r = j;
			}
			else if((pos_funname_r != -1) && (pos_funname_l == -1) && (str1[j] == ' '))
			{
				pos_funname_l = j + 1;
			}
			if ((pos_funname_r != -1) && (pos_funname_l != -1))
			{
				break;
			}
		}
		string funname = str1.substr(pos_funname_l, pos_funname_r - pos_funname_l + 1);

		//提取参数名
		string paraname="";
		auto pos_para = str2.find_first_not_of(' ');
		if (pos_para == string::npos)
		{
			paraname = "";
		}
		else
		{
			int pos = 0,savepos=0;
			for (int j = 0; j < str2.size(); j = pos + 1)
			{
				pos = j;
				savepos = pos;
				while ((str2[pos] != ',') && (pos<str2.size()))
				{
					pos++;
				}
				if (str2[pos] == ',')
				{
					int pos_paraname_r = -1, pos_paraname_l = -1;
					for (int k = pos-1; k >=j; k--)
					{
						if ((pos_paraname_r == -1) && (str2[k] != ' '))
						{
							pos_paraname_r = k;
						}
						else if ((pos_paraname_r != -1) && (pos_paraname_l == -1) && (str2[k] == ' '))
						{
							pos_paraname_l = k + 1;
						}
						if ((pos_paraname_r != -1) && (pos_paraname_l != -1))
						{
							break;
						}

					}
					paraname = paraname + ", " + str2.substr(pos_paraname_l, pos_paraname_r - pos_paraname_l+1);
				}

			}
			int pos_paraname_r = -1, pos_paraname_l = -1;
			for (int k = str2.size() - 1; k >= savepos; k--)
			{
				if ((pos_paraname_r == -1) && (str2[k] != ' '))
				{
					pos_paraname_r = k;
				}
				else if ((pos_paraname_r != -1) && (pos_paraname_l == -1) && (str2[k] == ' '))
				{
					pos_paraname_l = k + 1;
				}
				if ((pos_paraname_r != -1) && (pos_paraname_l != -1))
				{
					break;
				}

			}
			paraname = paraname + ", " + str2.substr(pos_paraname_l, pos_paraname_r - pos_paraname_l + 1);

		}
		functions_format[i] = functions_format[i] + "(" + funname + paraname + ")";
	}

	//创建文件并写入vector<string>
	ofstream fout("FunctionFormat.txt");
	if (fout)  // 如果创建成功
	{
		for (int i = 0; i < functions_format.size(); i++)
		{
			fout << functions_format[i] << endl;
		}
		fout.close();  // 执行完操作后关闭文件句柄
	}


	return 0;
}