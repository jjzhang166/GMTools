#include "AlertAddItem.h"
#include "UIEventManager.h"
#include "gmtools.h"
AlertAddItem::AlertAddItem(QWidget *parent)
: QMainWindow(parent)
{
	ui.setupUi(this);
	this->initAlert();
}

AlertAddItem::~AlertAddItem()
{

}
void AlertAddItem::initAlert()
{
	connect(ui.alert_btn_ok, SIGNAL(clicked()), this, SLOT(ClickByBottomOk()));

}

void AlertAddItem::ClickByBottomOk()
{
	QString value1 = ui.ed_01->text();
	QString value2 = ui.ed_02->text();
	QString value3 = ui.ed_03->text();
	qDebug(ui.ed_01->text().toStdString().data());
	//UIEventManager::getInstence()->getGmObject()->updateCmdWidget();
}