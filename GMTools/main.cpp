#include "gmtools.h"
#include "UIEventManager.h"
#include "ReadConfig.h"
#include "MacroDefinition.h"
#include "NetWorkManager.h"

#include <QtWidgets/QApplication>

#ifdef _WIN32
#include <WinSock2.h>
#pragma comment(lib , "ws2_32.lib")
#endif

int main(int argc, char *argv[])
{
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2,2), &wsaData) != 0)
	{  
		//qDebug("WSAStartup");
		return -1;
	}

	QApplication a(argc, argv);
	// 先读取数据
	ReadConfig::getInstence()->read();
	// 在初始化试图
	GMTools* gm = new GMTools();
	gm->show();
	// 注册UI代理
	UIEventManager::getInstence()->saveGmObject(gm);
	UIEventManager::getInstence()->updateUIMsg("配置文件加载完成");
	// 初始话网络接口，并不链接
	NetWorkManager::getInstence()->initNetWork();
	UIEventManager::getInstence()->updateUIMsg("软件初始化完成");
	//WSACleanup();
	return a.exec();
}
