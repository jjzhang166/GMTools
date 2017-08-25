#ifndef ITEMWIDGET_H
#define ITEMWIDGET_H

#include <QWidget>
#include "ui_ItemWidget.h"
#include <vector>
#include <string>
using namespace std;

class ItemWidget : public QWidget
{
	Q_OBJECT

public:
	ItemWidget(QWidget *parent = 0);
	~ItemWidget();
	void initView(vector<string> cmdVec);

private:
	Ui::ItemWidget ui;
	vector<QLineEdit*> sEditVector;

	QString sCmdHeand;
	
public slots:
	void onClickByExecute(vector<string> cmdVec);
};

#endif // ITEMWIDGET_H
