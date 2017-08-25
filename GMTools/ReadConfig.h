/********************************************************************
	created:	2016/08/25 15:54
	file base:	ReadConfig
	author:		sszyc8
	
	purpose:	数据读取类(单例)
*********************************************************************/
#pragma once

#include <vector>
using namespace std;

class ReadConfig
{
public:
	ReadConfig(void);
	~ReadConfig(void);
	
	static inline ReadConfig* getInstence()
	{
		if (!sReadConfig)
		{
			sReadConfig = new ReadConfig();
		}
		return sReadConfig;
	}
	static void destroyInstence(){
		if (sReadConfig)
		{
			delete sReadConfig;
			sReadConfig = NULL;
		}
	}
	void read(); // 读取配置文件
	inline int getSize(){return this->size;}
	inline vector<vector<string>> getCmdVec(){return this->sCmdVec;} // 读取命令集合
private:
	static ReadConfig* sReadConfig;
	int size;
	vector<vector<string>> sCmdVec;
	vector<string> sTempCmdVec;
};