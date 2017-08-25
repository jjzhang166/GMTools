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
	// �ȶ�ȡ����
	ReadConfig::getInstence()->read();
	// �ڳ�ʼ����ͼ
	GMTools* gm = new GMTools();
	gm->show();
	// ע��UI����
	UIEventManager::getInstence()->saveGmObject(gm);
	UIEventManager::getInstence()->updateUIMsg("�����ļ��������");
	// ��ʼ������ӿڣ���������
	NetWorkManager::getInstence()->initNetWork();
	UIEventManager::getInstence()->updateUIMsg("�����ʼ�����");
	//WSACleanup();
	return a.exec();
}
