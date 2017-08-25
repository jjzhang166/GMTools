#include "ItemWidget.h"
#include "NetWorkManager.h"

ItemWidget::ItemWidget(QWidget *parent)
: QWidget(parent),
sCmdHeand("")
{
	ui.setupUi(this);
	setFixedSize(250,50); // 禁止改变窗口大小。
	this->sEditVector.push_back(ui.lineEdit);
	this->sEditVector.push_back(ui.lineEdit_2);
	this->sEditVector.push_back(ui.lineEdit_3);
}

ItemWidget::~ItemWidget()
{

}

void ItemWidget::initView(vector<string> cmdVec)
{
	// 这只标题
	ui.groupBox->setTitle(cmdVec.back().c_str());
	// 获取头命令
	this->sCmdHeand = QString(QLatin1String(cmdVec[0].c_str()));
	// 去头去尾
	cmdVec.erase(cmdVec.begin());
	cmdVec.pop_back();
	
	// 初始化3个输入框
	for (int i=0; i<3; i++)
	{
		if (i<(cmdVec.size()))
		{
			((QLineEdit*)this->sEditVector[i])->setPlaceholderText(cmdVec[i].c_str()); // 设置文本提示
			// 设置只能输入数字
			QRegExp regx("[0-9]+$");
			QValidator* validator = new QRegExpValidator(regx, this->sEditVector[i]);
			this->sEditVector[i]->setValidator(validator);
		}else
		{
			((QLineEdit*)this->sEditVector[i])->setVisible(false);
		}
	}

	QObject::connect(ui.pushButton, &QPushButton::clicked, this, [=](){onClickByExecute(cmdVec);});
}

void ItemWidget::onClickByExecute(vector<string> cmdVec)
{
	QString cmd = this->sCmdHeand;
	if (cmdVec.size()>0)
	{
		for (int i=0;i<cmdVec.size();i++)
		{
			QLineEdit* qle = ((QLineEdit*)this->sEditVector[i]);
			qDebug("button print :%s ",qle->text());
			cmd.append(",").append(qle->text());
		}
	}else
	{
		cmd.append(",");
	}
	qDebug("cmd = %s",cmd.toStdString().c_str());
	NetWorkManager::getInstence()->SendToUid(cmd.toStdString().c_str());
}
