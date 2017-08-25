#include "gmtools.h"
#include "ItemWidget.h"
#include "AlertAddItem.h"
#include "ReadConfig.h"
#include "NetWorkManager.h"

#include <QMessageBox>
#include <QListWidget>
#include <time.h>
#include <QDateTime>

GMTools::GMTools(QWidget *parent)
: QMainWindow(parent)
{
	ui.setupUi(this);
	setFixedSize(640,710); // ��ֹ�ı䴰�ڴ�С��

	connect(ui.btn_help, SIGNAL(triggered()),this,SLOT(OnClickByHelp()));
	connect(ui.btn_about, SIGNAL(triggered()),this,SLOT(OnClickByAbout()));

	this->topWidget();
	this->initCenter();
	this->initBottomWidget();
}

GMTools::~GMTools()
{

}

//************************************
// ����˵��: ��ʼ��ͷ�����
// �� �� ֵ: void
//************************************
void GMTools::topWidget()
{
	// ����ֻ����������
	QRegExp regx_port("[0-9]+$");
	QValidator* validator_port = new QRegExpValidator(regx_port, ui.lineEdit_port);
	ui.lineEdit_port->setValidator(validator_port);

	// ����ֻ����������
	QRegExp regx_uid("[0-9]+$");
	QValidator* validator_uid = new QRegExpValidator(regx_uid, ui.lineEdit_uid);
	ui.lineEdit_uid->setValidator(validator_uid);
	// ��ť�¼�����
	QObject::connect(ui.top_btn_connect,SIGNAL(clicked()),this,SLOT(ClickByTopConnect()));
}

//************************************
// ����˵��: ��ʼ���в����
// �� �� ֵ: void
//************************************
void GMTools::initCenter()
{
	// ȥ�ո�
	QRegExp regx("\\S+");
	QValidator* validator = new QRegExpValidator(regx,ui.center_lineEdit);
	ui.center_lineEdit->setValidator(validator);
	QObject::connect(ui.center_btn_commit,SIGNAL(clicked()),this,SLOT(OnClickByCneterCommit()));
}

//************************************
// ����˵��: ��ʼ���ײ����(���ģʽ����Ϣ��ʾ)
// �� �� ֵ: void
//************************************
void GMTools::initBottomWidget()
{
	QScrollArea *pArea = ui.bottom_scroll_area;
	pArea->setWidgetResizable(false);
	ui.botton_scorill_area_widget->setGeometry(0,0,280,10000);
	int size = ReadConfig::getInstence()->getSize();
	vector<vector<string>> cmdVec = ReadConfig::getInstence()->getCmdVec();
	for (int i=0; i<size; i++)
	{
		ItemWidget* item = new ItemWidget(ui.botton_scorill_area_widget);
		item->initView(cmdVec[i]);
		item->move(8,i*item->height());
		// TOTO �������
	}
}

//************************************
// ����˵��: ���������б���Ϣ
// �� �� ֵ: void
// ��    ��: char * msg
//************************************
void GMTools::updateCmd(QString pCmd)
{
	ui.center_lineEdit->setText(pCmd);
}

//************************************
// ����˵��: �����б���ʾ��Ϣ
// �� �� ֵ: void
// ��    ��: char * msg
//************************************
void GMTools::updateMsg(char* msg)
{
	/*
	time_t t = time( 0 );
	char tmp[25];
	strftime( tmp, sizeof(tmp), "%Y/%m/%d %X",localtime(&t) );
	qDebug("%s",tmp);
	*/
	QString current_date = QDateTime::currentDateTime().toString("hh:mm:ss");
	current_date.append(" ").append(QString::fromLocal8Bit(msg));
	current_date.replace(QString("\n"), QString("")).replace(QString("\r"),QString(""));
	QListWidgetItem *item = new QListWidgetItem(ui.bottom_listWidget);
	item->setData(Qt::DisplayRole,QObject::tr(current_date.toStdString().c_str()));
}

//************************************
// ����˵��: ��ť�¼�->����
// �� �� ֵ: void
//************************************
void GMTools::OnClickByAbout()
{
	QMessageBox::about(this,QStringLiteral("����"),QStringLiteral("��Ŀ��ַ http://www.xxoo.com"));
}

//************************************
// ����˵��: ��ť�¼�->����
// �� �� ֵ: void
//************************************
void GMTools::OnClickByHelp()
{
	QMessageBox::about(this,QStringLiteral("����"),QStringLiteral("�����޸���exeͬ��Ŀ¼�µ�config�ļ�������̬���������У�ȥ��Uid�⣬���֧������������"));
};

//************************************
// ����˵��: ��ť�¼�->���ӵ�������
// �� �� ֵ: void
//************************************
void GMTools::ClickByTopConnect()
{
	char* ip = (char*)malloc(sizeof( ui.lineEdit_ip->text().toStdString().c_str()));
	strcpy(ip, ui.lineEdit_ip->text().toStdString().c_str());
	QString uid = ui.lineEdit_uid->text().toStdString().c_str();
	const int port	= ui.lineEdit_port->text().toInt();
	if (uid.isEmpty())
	{
		this->updateMsg("UID����Ϊ�գ�");
		return;
	}
	int res = NetWorkManager::getInstence()->connectSock(ip,port,uid);
	if (res==0)
	{
		qDebug("connect sock success!!!");
		ui.top_btn_connect->setEnabled(false);
		ui.top_btn_connect->setText("ok");
		// �������ӳɹ������߳�
		NetWorkManager::getInstence()->initNetThread();
	}else
	{
		//QMessageBox::critical(this, QStringLiteral("��ʾ"),QStringLiteral("���ӷ�����ʧ�ܣ�����"),QMessageBox::Ok);  
		qDebug("connect sock error!!!");
	}
}

void GMTools::OnClickByCneterCommit()
{
	QString cmd = ui.center_lineEdit->text().toStdString().c_str();
	if (!cmd.isEmpty())
	{
		NetWorkManager::getInstence()->Send(cmd.toStdString().c_str());
	}
}

