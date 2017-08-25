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
	setFixedSize(640,710); // 禁止改变窗口大小。

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
// 函数说明: 初始化头部组件
// 返 回 值: void
//************************************
void GMTools::topWidget()
{
	// 设置只能输入数字
	QRegExp regx_port("[0-9]+$");
	QValidator* validator_port = new QRegExpValidator(regx_port, ui.lineEdit_port);
	ui.lineEdit_port->setValidator(validator_port);

	// 设置只能输入数字
	QRegExp regx_uid("[0-9]+$");
	QValidator* validator_uid = new QRegExpValidator(regx_uid, ui.lineEdit_uid);
	ui.lineEdit_uid->setValidator(validator_uid);
	// 按钮事件处理
	QObject::connect(ui.top_btn_connect,SIGNAL(clicked()),this,SLOT(ClickByTopConnect()));
}

//************************************
// 函数说明: 初始化中部组件
// 返 回 值: void
//************************************
void GMTools::initCenter()
{
	// 去空格
	QRegExp regx("\\S+");
	QValidator* validator = new QRegExpValidator(regx,ui.center_lineEdit);
	ui.center_lineEdit->setValidator(validator);
	QObject::connect(ui.center_btn_commit,SIGNAL(clicked()),this,SLOT(OnClickByCneterCommit()));
}

//************************************
// 函数说明: 初始化底部组件(快捷模式和信息提示)
// 返 回 值: void
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
		// TOTO 清理操作
	}
}

//************************************
// 函数说明: 更新命令列表信息
// 返 回 值: void
// 参    数: char * msg
//************************************
void GMTools::updateCmd(QString pCmd)
{
	ui.center_lineEdit->setText(pCmd);
}

//************************************
// 函数说明: 更新列表提示信息
// 返 回 值: void
// 参    数: char * msg
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
// 函数说明: 按钮事件->关于
// 返 回 值: void
//************************************
void GMTools::OnClickByAbout()
{
	QMessageBox::about(this,QStringLiteral("关于"),QStringLiteral("项目地址 http://www.xxoo.com"));
}

//************************************
// 函数说明: 按钮事件->帮助
// 返 回 值: void
//************************************
void GMTools::OnClickByHelp()
{
	QMessageBox::about(this,QStringLiteral("帮助"),QStringLiteral("可以修改在exe同级目录下的config文件，来动态增加命令行，去除Uid外，最多支持三个参数。"));
};

//************************************
// 函数说明: 按钮事件->连接到服务器
// 返 回 值: void
//************************************
void GMTools::ClickByTopConnect()
{
	char* ip = (char*)malloc(sizeof( ui.lineEdit_ip->text().toStdString().c_str()));
	strcpy(ip, ui.lineEdit_ip->text().toStdString().c_str());
	QString uid = ui.lineEdit_uid->text().toStdString().c_str();
	const int port	= ui.lineEdit_port->text().toInt();
	if (uid.isEmpty())
	{
		this->updateMsg("UID不能为空！");
		return;
	}
	int res = NetWorkManager::getInstence()->connectSock(ip,port,uid);
	if (res==0)
	{
		qDebug("connect sock success!!!");
		ui.top_btn_connect->setEnabled(false);
		ui.top_btn_connect->setText("ok");
		// 连接连接成功启动线程
		NetWorkManager::getInstence()->initNetThread();
	}else
	{
		//QMessageBox::critical(this, QStringLiteral("提示"),QStringLiteral("连接服务器失败！！！"),QMessageBox::Ok);  
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

