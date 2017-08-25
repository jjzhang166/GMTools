#include "NetWorkManager.h"
#include "MacroDefinition.h"
#include "NetWork.h"
#include <QtWidgets/QMainWindow>
#include "UIEventManager.h"

NetWorkManager* NetWorkManager::sNetWorkManager = NULL;

NetWorkManager::NetWorkManager(void)
{
}

NetWorkManager::~NetWorkManager(void)
{
}


//************************************
// ����˵��: ��ʼ��socket
// �� �� ֵ: int
//************************************
int NetWorkManager::initNetWork()
{
	this->sNetWork = new NetWork();
	UIEventManager::getInstence()->updateUIMsg("�����ʼ�����");
	return 0;
}

//************************************
// ����˵��: ��ʼ�������߳�
// �� �� ֵ: void
//************************************
void NetWorkManager::initNetThread()
{
	this->sNetWork->initRecvThread();
}

//************************************
// ����˵��: ���ӵ�������
// �� �� ֵ: int ִ�н��
// ��    ��: const char * ip
// ��    ��: const int port
// ��    ��: QString pUid �û�uid
//************************************
int NetWorkManager::connectSock(const char*ip, const int port, QString pUid)
{
	this->uid = QString("u").append(pUid);
	qDebug("connect Sock ip:%s , port:%d , uid:%s",ip,port,pUid);

	if (this->sNetWork->connectSock(ip,port)==SOCKET_ERROR)
	{
		UIEventManager::getInstence()->updateUIMsg("���ӵ�������ʧ�ܣ�");
		return -1;
	}
	UIEventManager::getInstence()->updateUIMsg("���ӵ��������ɹ���");
	return 0;
}

//************************************
// ����˵��: ������Ϣ
// �� �� ֵ: int
// ��    ��: const char * cmd
//************************************
int NetWorkManager::Send(const char *cmd)
{
	return this->sNetWork->sendMsg(cmd);
}


//************************************
// ����˵��: ͨ��UID������Ϣ
// �� �� ֵ: int
// ��    ��: const char * cmd
//************************************
int NetWorkManager::SendToUid(QString pCmd)
{
	// cmdԭ�� addprop,u216454259881934849,1131,999,1
	int pos = pCmd.indexOf(",");
	pCmd.insert(pos,"," + this->uid);
	if (pCmd.right(1)==",") // ȥ�����һλ","
	{
		pCmd.remove(pCmd.size()-1,1);
	}
	// ����UI����
	UIEventManager::getInstence()->updateUICmd(pCmd);
	return this->sNetWork->sendMsg(pCmd.toStdString().c_str());
}

int NetWorkManager::getFd()
{
	return this->sNetWork->getFd();
}

//************************************
// ����˵��: ���������֪ͨ�������������Ӧ����
// �� �� ֵ: void
// ��    ��: int code ������
// ��    ��: char * res �������
//************************************
void NetWorkManager::Recv(int code, char* res )
{
	UIEventManager::getInstence()->updateUIMsg(res);
}

