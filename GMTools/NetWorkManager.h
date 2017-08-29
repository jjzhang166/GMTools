#pragma once
#include <QString>
class NetWork;

class NetWorkManager
{
public:
	NetWorkManager(void);
	~NetWorkManager(void);
	// 单例
	static inline NetWorkManager* getInstence()
	{
		if (!sNetWorkManager)
		{
			sNetWorkManager = new NetWorkManager;
		}
		return sNetWorkManager;
	}
	int initNetWork();								// 初始化网络
	int connectSock(const char *ip, const unsigned short port, QString pUid);	// 连接到服务器
	void initNetThread();							// 初始化监听线程
	int Send(const char *cmd);						// 发送消息
	int SendToUid(QString pCmd);					// 通过uid来发送消息
	void Recv(int code, char* res );				// 服务器返回结果
	void SetUid(QString pUid);						// 设置用户uid
	int getFd();									// 获取当前连接的句柄文件/描述符
	inline QString GetUid(){return this->uid;}		// 获取用户UID
private:
	static NetWorkManager* sNetWorkManager;
	NetWork* sNetWork;
	QString uid;
};

