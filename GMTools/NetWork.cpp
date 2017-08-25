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
// ����˵��: ��ʼ��sock
// �� �� ֵ: int ��ʼ�����
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
// ����˵��: ���ӵ�������
// �� �� ֵ: int ����״̬
// ��    ��: const char * ip ip��ַ
// ��    ��: const int port �˿ں�
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
// ����˵��: ������Ϣ
// �� �� ֵ: int ������
// ��    ��: QString cmd ��Ҫ���͵�����(ִ�е�����)
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
		qDebug(QStringLiteral("���ݷ���ʧ��").toStdString().c_str());
		return SOCKET_ERROR;
	}
	else
	{
		qDebug(QStringLiteral("��Ϣ���ͳɹ�").toStdString().c_str());
		return 0;
	}
}

//************************************
// ����˵��: ��ʼ���̷߳��ؼ���
// �� �� ֵ: void
//************************************
void NetWork::initRecvThread()
{
	HANDLE recvHandle = (HANDLE)_beginthreadex(NULL,0,this->recvMsg,(void*)&this->fd,0,NULL);
	WaitForSingleObject(recvHandle,NULL);
}

//************************************
// ����˵��: �߳�ִ�к���
// �� �� ֵ: unsigned __stdcall
// ��    ��: void * argc
//************************************
unsigned __stdcall NetWork::recvMsg(void* argc)
{
	qDebug(QStringLiteral("��ʼ�����ݽ����߳�").toStdString().c_str());
	SOCKET sock = *((SOCKET*)argc);
	char readBuf[1024];
	while (true)
	{
		memset(readBuf,0,sizeof(readBuf)/sizeof(char));
		//qDebug("readbuf%d",sizeof(readBuf));
		qDebug(QStringLiteral("�����ȴ���������������").toStdString().c_str());
		int res = ::recv(sock,readBuf,sizeof(readBuf),0);
		//qDebug("recv = %d",WSAGetLastError());
		NetWorkManager::getInstence()->Recv(res,readBuf);
		if (res==SOCKET_ERROR)
		{
			qDebug("sock recv error");
		}else{
			qDebug(QStringLiteral("��������������").toStdString().c_str());
			qDebug(readBuf);
		}
	}
	qDebug(QStringLiteral("���ݽ����߳��˳�!!!").toStdString().c_str());
	return 0;
}