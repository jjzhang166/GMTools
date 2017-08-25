/********************************************************************
	created:	2016/08/25 15:54
	file base:	ReadConfig
	author:		sszyc8
	
	purpose:	数据读取类(单例)
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
// 函数说明: 字符串分割
// 返 回 值: void
// 参    数: const string & s 要操作的字符串
// 参    数: vector<string> & v 用于保存操作结果
// 参    数: const string & c 查找条件
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
// 函数说明: 加载配置文件
// 返 回 值: void 
//************************************
void ReadConfig::read()
{
	const char* filename="config";
	ifstream infile; 
	infile.open(filename);
	assert(infile.is_open());

	qDebug(QStringLiteral("读取文件开始。。。。。。。。。。。。").toStdString().c_str());
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
	qDebug(QStringLiteral("读取文件结束。。。。。。。。。。。。").toStdString().c_str());
}
