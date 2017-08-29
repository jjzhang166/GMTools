#pragma once

#include <Windows.h>
#include <QString>

class NetWork
{
public:
	NetWork(void);
	~NetWork(void);

	int connectSock(const char*ip, const unsigned short port); // 链接到服务器
	void initRecvThread(); // 启动线程函数
	int sendMsg(QString str); // 发送消息
	inline int getFd(){return this->fd;} //获取句柄
private:
	int fd;
	int initSock(); // 初始化sock
	static unsigned WINAPI recvMsg(void* argc); // 线程执行函数
};

