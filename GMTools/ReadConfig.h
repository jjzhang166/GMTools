/********************************************************************
	created:	2016/08/25 15:54
	file base:	ReadConfig
	author:		sszyc8
	
	purpose:	���ݶ�ȡ��(����)
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
	void read(); // ��ȡ�����ļ�
	inline int getSize(){return this->size;}
	inline vector<vector<string>> getCmdVec(){return this->sCmdVec;} // ��ȡ�����
private:
	static ReadConfig* sReadConfig;
	int size;
	vector<vector<string>> sCmdVec;
	vector<string> sTempCmdVec;
};