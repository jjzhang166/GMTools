#pragma once
#include <QString>
class NetWork;

class NetWorkManager
{
public:
	NetWorkManager(void);
	~NetWorkManager(void);
	// ����
	static inline NetWorkManager* getInstence()
	{
		if (!sNetWorkManager)
		{
			sNetWorkManager = new NetWorkManager;
		}
		return sNetWorkManager;
	}
	int initNetWork();								// ��ʼ������
	int connectSock(const char *ip, const unsigned short port, QString pUid);	// ���ӵ�������
	void initNetThread();							// ��ʼ�������߳�
	int Send(const char *cmd);						// ������Ϣ
	int SendToUid(QString pCmd);					// ͨ��uid��������Ϣ
	void Recv(int code, char* res );				// ���������ؽ��
	void SetUid(QString pUid);						// �����û�uid
	int getFd();									// ��ȡ��ǰ���ӵľ���ļ�/������
	inline QString GetUid(){return this->uid;}		// ��ȡ�û�UID
private:
	static NetWorkManager* sNetWorkManager;
	NetWork* sNetWork;
	QString uid;
};

