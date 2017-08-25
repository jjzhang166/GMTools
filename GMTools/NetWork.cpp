#include "NetWork.h"
#include "MacroDefinition.h"
#include "NetWorkManager.h"

#include <process.h>
#include <qlogging.h>
#include <QString>

NetWork::NetWork(void)
:fd(0)
{
	this->initSock();
}


NetWork::~NetWork(void)
{
}


//************************************
// 函数说明: 初始化sock
// 返 回 值: int 初始化结果
//************************************
int NetWork::initSock()
{
	this->fd = socket(AF_INET,SOCK_STREAM,0);
	if (this->fd==SOCKET_ERROR)
	{
		qDebug("sock create error");
	}else
	{
		qDebug("sock create success fd code:%d",this->fd);
	}
	return 0;
}

//************************************
// 函数说明: 连接到服务器
// 返 回 值: int 链接状态
// 参    数: const char * ip ip地址
// 参    数: const int port 端口号
//************************************
int NetWork::connectSock(const char*ip, const int port)
{
	struct sockaddr_in addr;
	memset(&addr,0,sizeof(addr));
	addr.sin_family = PF_INET;
	addr.sin_addr.s_addr = inet_addr(ip);
	addr.sin_port = htons(port);
	if (::connect(this->fd,(struct sockaddr*)&addr,sizeof(addr))==SOCKET_ERROR)
	{
		qDebug("connectSock ERROR");
		return SOCKET_ERROR;
	}else
	{
		qDebug("connectSock success");
		return 0;
	}
}

//************************************
// 函数说明: 发送消息
// 返 回 值: int 处理结果
// 参    数: QString cmd 所要发送的数据(执行的命令)
//************************************
int NetWork::sendMsg(QString cmd)
{
	qDebug("send to server cmd :(%s) lenth :%d",cmd.toStdString().c_str(),cmd.size());
	cmd.append(",-1\r");
	int ret = send(this->fd,cmd.toStdString().c_str(),cmd.size(),0);
	//qDebug("ret send = %d",ret);
	//qDebug("ret send code= %d",WSAGetLastError());
	if(ret == SOCKET_ERROR)
	{
		qDebug(QStringLiteral("数据发送失败").toStdString().c_str());
		return SOCKET_ERROR;
	}
	else
	{
		qDebug(QStringLiteral("消息发送成功").toStdString().c_str());
		return 0;
	}
}

//************************************
// 函数说明: 初始化线程返回监听
// 返 回 值: void
//************************************
void NetWork::initRecvThread()
{
	HANDLE recvHandle = (HANDLE)_beginthreadex(NULL,0,this->recvMsg,(void*)&this->fd,0,NULL);
	WaitForSingleObject(recvHandle,NULL);
}

//************************************
// 函数说明: 线程执行函数
// 返 回 值: unsigned __stdcall
// 参    数: void * argc
//************************************
unsigned __stdcall NetWork::recvMsg(void* argc)
{
	qDebug(QStringLiteral("初始化数据接收线程").toStdString().c_str());
	SOCKET sock = *((SOCKET*)argc);
	char readBuf[1024];
	while (true)
	{
		memset(readBuf,0,sizeof(readBuf)/sizeof(char));
		//qDebug("readbuf%d",sizeof(readBuf));
		qDebug(QStringLiteral("阻塞等待服务器返回数据").toStdString().c_str());
		int res = ::recv(sock,readBuf,sizeof(readBuf),0);
		//qDebug("recv = %d",WSAGetLastError());
		NetWorkManager::getInstence()->Recv(res,readBuf);
		if (res==SOCKET_ERROR)
		{
			qDebug("sock recv error");
		}else{
			qDebug(QStringLiteral("服务器返回数据").toStdString().c_str());
			qDebug(readBuf);
		}
	}
	qDebug(QStringLiteral("数据接收线程退出!!!").toStdString().c_str());
	return 0;
}