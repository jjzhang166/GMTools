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
// 函数说明: 初始化socket
// 返 回 值: int
//************************************
int NetWorkManager::initNetWork()
{
	this->sNetWork = new NetWork();
	UIEventManager::getInstence()->updateUIMsg("网络初始化完成");
	return 0;
}

//************************************
// 函数说明: 初始化工作线程
// 返 回 值: void
//************************************
void NetWorkManager::initNetThread()
{
	this->sNetWork->initRecvThread();
}

//************************************
// 函数说明: 链接到服务器
// 返 回 值: int 执行结果
// 参    数: const char * ip
// 参    数: const int port
// 参    数: QString pUid 用户uid
//************************************
int NetWorkManager::connectSock(const char*ip, const int port, QString pUid)
{
	this->uid = QString("u").append(pUid);
	qDebug("connect Sock ip:%s , port:%d , uid:%s",ip,port,pUid);

	if (this->sNetWork->connectSock(ip,port)==SOCKET_ERROR)
	{
		UIEventManager::getInstence()->updateUIMsg("连接到服务器失败！");
		return -1;
	}
	UIEventManager::getInstence()->updateUIMsg("连接到服务器成功！");
	return 0;
}

//************************************
// 函数说明: 发送消息
// 返 回 值: int
// 参    数: const char * cmd
//************************************
int NetWorkManager::Send(const char *cmd)
{
	return this->sNetWork->sendMsg(cmd);
}


//************************************
// 函数说明: 通过UID发送消息
// 返 回 值: int
// 参    数: const char * cmd
//************************************
int NetWorkManager::SendToUid(QString pCmd)
{
	// cmd原型 addprop,u216454259881934849,1131,999,1
	int pos = pCmd.indexOf(",");
	pCmd.insert(pos,"," + this->uid);
	if (pCmd.right(1)==",") // 去掉最后一位","
	{
		pCmd.remove(pCmd.size()-1,1);
	}
	// 更新UI命令
	UIEventManager::getInstence()->updateUICmd(pCmd);
	return this->sNetWork->sendMsg(pCmd.toStdString().c_str());
}

int NetWorkManager::getFd()
{
	return this->sNetWork->getFd();
}

//************************************
// 函数说明: 用于网络端通知网络管理类做响应处理
// 返 回 值: void
// 参    数: int code 返回码
// 参    数: char * res 结果内容
//************************************
void NetWorkManager::Recv(int code, char* res )
{
	UIEventManager::getInstence()->updateUIMsg(res);
}

