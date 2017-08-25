/********************************************************************
	created:	2016/08/25 15:54
	file base:	ReadConfig
	author:		sszyc8
	
	purpose:	���ݶ�ȡ��(����)
*********************************************************************/

#include "ReadConfig.h"
#include "UIEventManager.h"

#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <QtCore/qglobal.h>
#include <vector>
#include <QString>
using namespace std;

ReadConfig* ReadConfig::sReadConfig = NULL;


//************************************
// ����˵��: �ַ����ָ�
// �� �� ֵ: void
// ��    ��: const string & s Ҫ�������ַ���
// ��    ��: vector<string> & v ���ڱ���������
// ��    ��: const string & c ��������
//************************************
void SplitString(const string& s, vector<string>& v, const string& c)
{
	string::size_type pos1, pos2;
	pos2 = s.find(c);
	pos1 = 0;
	while(string::npos != pos2)
	{
		v.push_back(s.substr(pos1, pos2-pos1));
		pos1 = pos2 + c.size();
		pos2 = s.find(c, pos1);
	}
	if(pos1 != s.length())
		v.push_back(s.substr(pos1));
}

ReadConfig::ReadConfig(void)
:size(0)
{
}

ReadConfig::~ReadConfig(void)
{
	this->sCmdVec.clear();
	this->sTempCmdVec.clear();
}

//************************************
// ����˵��: ���������ļ�
// �� �� ֵ: void 
//************************************
void ReadConfig::read()
{
	const char* filename="config";
	ifstream infile; 
	infile.open(filename);
	assert(infile.is_open());

	qDebug(QStringLiteral("��ȡ�ļ���ʼ������������������������").toStdString().c_str());
	string s;
	while(getline(infile,s))
	{
		qDebug("%s",s.c_str());
		this->sTempCmdVec.clear();
		SplitString(s,this->sTempCmdVec,",");
		this->sCmdVec.push_back(this->sTempCmdVec);
		size++;
	}
	infile.close();
	qDebug(QStringLiteral("��ȡ�ļ�����������������������������").toStdString().c_str());
}
