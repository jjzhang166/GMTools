#ifndef GMTOOLS_H
#define GMTOOLS_H

#include <QtWidgets/QMainWindow>
#include "ui_gmtools.h"

class GMTools : public QMainWindow
{
	Q_OBJECT

public:
	GMTools(QWidget *parent = 0);
	~GMTools();
	void updateMsg(char* msg);
	void updateCmd(QString qCmd);
private:
	Ui::GMToolsClass ui;
	void topWidget();
	void initCenter();
	void initBottomWidget();

public slots:
	void OnClickByHelp();
	void OnClickByAbout();
	void ClickByTopConnect();
	void OnClickByCneterCommit();
//	void ClickByBottomAdd();
//	void ClickByBottomDel();


};

#endif // GMTOOLS_H
