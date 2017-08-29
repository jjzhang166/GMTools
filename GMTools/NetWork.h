#pragma once

#include <Windows.h>
#include <QString>

class NetWork
{
public:
	NetWork(void);
	~NetWork(void);

	int connectSock(const char*ip, const unsigned short port); // ���ӵ�������
	void initRecvThread(); // �����̺߳���
	int sendMsg(QString str); // ������Ϣ
	inline int getFd(){return this->fd;} //��ȡ���
private:
	int fd;
	int initSock(); // ��ʼ��sock
	static unsigned WINAPI recvMsg(void* argc); // �߳�ִ�к���
};

