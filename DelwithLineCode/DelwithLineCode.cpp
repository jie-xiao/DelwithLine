#include "stdafx.h"
//清除网上下载代码前自带行数小程序
//作者：陈永余   时间：2018.03.08
using namespace std;
int main()
{
	char FileName[50];
	char* ptr;
	ifstream InputFile;
	ofstream OutFile;
	char OutFileName[50];
	int Line;
	char buf[512];
	cout << "修改前请先备份" << endl;
	cout << "输入文件绝对路径：";
	cin >> FileName;
	cout << "输入文件路径为：" << FileName << endl;
	cout << "输出文件绝对路径：";
	cin >> OutFileName;
	InputFile.open(FileName, ifstream::_Nocreate);
	OutFile.open(OutFileName, ifstream::app);
	if (InputFile.fail())
		cout << "无法找到输入文件，请确认文件路径是否正确。" << endl;
	else
	{
		cout << "请输入需改变的行数（目前仅支持txt等文本格式左起行数）：";
		cin >> Line;
		cout << "行数为" << Line << endl;
	}
	while (InputFile.eof() == 0)
	{
		InputFile.getline(buf, 512);
		ptr = buf + Line;
		OutFile.write(ptr, strlen(ptr));
		OutFile.put('\n');
		OutFile.flush();
	}
	InputFile.close();
	OutFile.close();
	cout << "ok" << endl;
	system("pause");
	return 0;
}