#include "stdafx.h"
//����������ش���ǰ�Դ�����С����
//���ߣ�������   ʱ�䣺2018.03.08
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
	cout << "�޸�ǰ���ȱ���" << endl;
	cout << "�����ļ�����·����";
	cin >> FileName;
	cout << "�����ļ�·��Ϊ��" << FileName << endl;
	cout << "����ļ�����·����";
	cin >> OutFileName;
	InputFile.open(FileName, ifstream::_Nocreate);
	OutFile.open(OutFileName, ifstream::app);
	if (InputFile.fail())
		cout << "�޷��ҵ������ļ�����ȷ���ļ�·���Ƿ���ȷ��" << endl;
	else
	{
		cout << "��������ı��������Ŀǰ��֧��txt���ı���ʽ������������";
		cin >> Line;
		cout << "����Ϊ" << Line << endl;
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