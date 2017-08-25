#ifndef ALERTADDITEM_H
#define ALERTADDITEM_H

#include <QMainWindow>
#include "ui_AlertAddItem.h"
class AlertAddItem : public QMainWindow
{
	Q_OBJECT

public:
	AlertAddItem(QWidget *parent = 0);
	~AlertAddItem();

private:
	Ui::AlertAddItem ui;
	void initAlert();

public slots:
	void ClickByBottomOk();
};

#endif // ALERTADDITEM_H
