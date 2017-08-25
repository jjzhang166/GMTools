#include "ItemWidget.h"
#include "NetWorkManager.h"

ItemWidget::ItemWidget(QWidget *parent)
: QWidget(parent),
sCmdHeand("")
{
	ui.setupUi(this);
	setFixedSize(250,50); // ��ֹ�ı䴰�ڴ�С��
	this->sEditVector.push_back(ui.lineEdit);
	this->sEditVector.push_back(ui.lineEdit_2);
	this->sEditVector.push_back(ui.lineEdit_3);
}

ItemWidget::~ItemWidget()
{

}

void ItemWidget::initView(vector<string> cmdVec)
{
	// ��ֻ����
	ui.groupBox->setTitle(cmdVec.back().c_str());
	// ��ȡͷ����
	this->sCmdHeand = QString(QLatin1String(cmdVec[0].c_str()));
	// ȥͷȥβ
	cmdVec.erase(cmdVec.begin());
	cmdVec.pop_back();
	
	// ��ʼ��3�������
	for (int i=0; i<3; i++)
	{
		if (i<(cmdVec.size()))
		{
			((QLineEdit*)this->sEditVector[i])->setPlaceholderText(cmdVec[i].c_str()); // �����ı���ʾ
			// ����ֻ����������
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
