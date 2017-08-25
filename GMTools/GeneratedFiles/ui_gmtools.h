/********************************************************************************
** Form generated from reading UI file 'gmtools.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GMTOOLS_H
#define UI_GMTOOLS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GMToolsClass
{
public:
    QAction *btn_help;
    QAction *action;
    QAction *btn_about;
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit_ip;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_port;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_uid;
    QPushButton *top_btn_connect;
    QGroupBox *groupBox_2;
    QPushButton *center_btn_commit;
    QLineEdit *center_lineEdit;
    QLabel *label_4;
    QGroupBox *groupBox_3;
    QScrollArea *bottom_scroll_area;
    QWidget *botton_scorill_area_widget;
    QPushButton *bottom_btn_del;
    QPushButton *bottom_btn_add;
    QGroupBox *groupBox_4;
    QListWidget *bottom_listWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GMToolsClass)
    {
        if (GMToolsClass->objectName().isEmpty())
            GMToolsClass->setObjectName(QStringLiteral("GMToolsClass"));
        GMToolsClass->resize(640, 716);
        GMToolsClass->setMinimumSize(QSize(0, 0));
        GMToolsClass->setCursor(QCursor(Qt::PointingHandCursor));
        GMToolsClass->setWindowOpacity(8);
        GMToolsClass->setStyleSheet(QStringLiteral("font: 9pt \"Courier New\";"));
        btn_help = new QAction(GMToolsClass);
        btn_help->setObjectName(QStringLiteral("btn_help"));
        action = new QAction(GMToolsClass);
        action->setObjectName(QStringLiteral("action"));
        btn_about = new QAction(GMToolsClass);
        btn_about->setObjectName(QStringLiteral("btn_about"));
        centralWidget = new QWidget(GMToolsClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 620, 90));
        groupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 30, 470, 46));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        lineEdit_ip = new QLineEdit(layoutWidget);
        lineEdit_ip->setObjectName(QStringLiteral("lineEdit_ip"));

        verticalLayout->addWidget(lineEdit_ip);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        lineEdit_port = new QLineEdit(layoutWidget);
        lineEdit_port->setObjectName(QStringLiteral("lineEdit_port"));

        verticalLayout_2->addWidget(lineEdit_port);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font;
        font.setFamily(QStringLiteral("Courier New"));
        font.setPointSize(9);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label_3->setFont(font);
        label_3->setAutoFillBackground(false);

        verticalLayout_3->addWidget(label_3);

        lineEdit_uid = new QLineEdit(layoutWidget);
        lineEdit_uid->setObjectName(QStringLiteral("lineEdit_uid"));

        verticalLayout_3->addWidget(lineEdit_uid);


        horizontalLayout->addLayout(verticalLayout_3);

        top_btn_connect = new QPushButton(groupBox);
        top_btn_connect->setObjectName(QStringLiteral("top_btn_connect"));
        top_btn_connect->setGeometry(QRect(484, 26, 131, 51));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 110, 620, 90));
        center_btn_commit = new QPushButton(groupBox_2);
        center_btn_commit->setObjectName(QStringLiteral("center_btn_commit"));
        center_btn_commit->setGeometry(QRect(484, 30, 131, 51));
        center_lineEdit = new QLineEdit(groupBox_2);
        center_lineEdit->setObjectName(QStringLiteral("center_lineEdit"));
        center_lineEdit->setEnabled(true);
        center_lineEdit->setGeometry(QRect(12, 43, 464, 37));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(12, 22, 36, 16));
        label_4->setFont(font);
        center_lineEdit->raise();
        label_4->raise();
        center_btn_commit->raise();
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 211, 301, 431));
        bottom_scroll_area = new QScrollArea(groupBox_3);
        bottom_scroll_area->setObjectName(QStringLiteral("bottom_scroll_area"));
        bottom_scroll_area->setGeometry(QRect(10, 20, 281, 351));
        bottom_scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        bottom_scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        bottom_scroll_area->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        bottom_scroll_area->setWidgetResizable(true);
        botton_scorill_area_widget = new QWidget();
        botton_scorill_area_widget->setObjectName(QStringLiteral("botton_scorill_area_widget"));
        botton_scorill_area_widget->setGeometry(QRect(0, 0, 262, 349));
        bottom_scroll_area->setWidget(botton_scorill_area_widget);
        bottom_btn_del = new QPushButton(groupBox_3);
        bottom_btn_del->setObjectName(QStringLiteral("bottom_btn_del"));
        bottom_btn_del->setGeometry(QRect(210, 380, 75, 31));
        bottom_btn_add = new QPushButton(groupBox_3);
        bottom_btn_add->setObjectName(QStringLiteral("bottom_btn_add"));
        bottom_btn_add->setGeometry(QRect(130, 380, 75, 31));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(319, 211, 311, 431));
        groupBox_4->setFlat(false);
        bottom_listWidget = new QListWidget(groupBox_4);
        bottom_listWidget->setObjectName(QStringLiteral("bottom_listWidget"));
        bottom_listWidget->setGeometry(QRect(5, 21, 301, 401));
        GMToolsClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GMToolsClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 640, 21));
        menuBar->setDefaultUp(false);
        menuBar->setNativeMenuBar(false);
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        GMToolsClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(GMToolsClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GMToolsClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addSeparator();
        menu->addAction(btn_help);
        menu->addSeparator();
        menu->addAction(btn_about);

        retranslateUi(GMToolsClass);

        QMetaObject::connectSlotsByName(GMToolsClass);
    } // setupUi

    void retranslateUi(QMainWindow *GMToolsClass)
    {
        GMToolsClass->setWindowTitle(QApplication::translate("GMToolsClass", "GMTools", 0));
        btn_help->setText(QApplication::translate("GMToolsClass", "\344\275\277\347\224\250\350\257\264\346\230\216", 0));
        action->setText(QApplication::translate("GMToolsClass", "\345\205\263\344\272\216GMTool", 0));
        btn_about->setText(QApplication::translate("GMToolsClass", "\345\205\263\344\272\216GMTool", 0));
        groupBox->setTitle(QApplication::translate("GMToolsClass", "\351\223\276\346\216\245\350\256\276\347\275\256", 0));
        label->setText(QApplication::translate("GMToolsClass", "IP\345\234\260\345\235\200\357\274\232", 0));
        label_2->setText(QApplication::translate("GMToolsClass", "\347\253\257\345\217\243\345\217\267\357\274\232", 0));
        lineEdit_port->setText(QString());
        label_3->setText(QApplication::translate("GMToolsClass", "\347\224\250\346\210\267UID\357\274\232", 0));
        top_btn_connect->setText(QApplication::translate("GMToolsClass", "\351\223\276\346\216\245\346\234\215\345\212\241\345\231\250", 0));
        groupBox_2->setTitle(QApplication::translate("GMToolsClass", "\345\221\275\344\273\244\346\250\241\345\274\217", 0));
        center_btn_commit->setText(QApplication::translate("GMToolsClass", "\346\211\247\350\241\214", 0));
        label_4->setText(QApplication::translate("GMToolsClass", "\345\221\275\344\273\244\357\274\232", 0));
        groupBox_3->setTitle(QApplication::translate("GMToolsClass", "\345\277\253\346\215\267\346\250\241\345\274\217", 0));
        bottom_btn_del->setText(QApplication::translate("GMToolsClass", "\345\210\240\351\231\244", 0));
        bottom_btn_add->setText(QApplication::translate("GMToolsClass", "\345\242\236\345\212\240", 0));
        groupBox_4->setTitle(QApplication::translate("GMToolsClass", "\344\277\241\346\201\257\346\217\220\347\244\272", 0));
        menu->setTitle(QApplication::translate("GMToolsClass", "\345\270\256\345\212\251", 0));
    } // retranslateUi

};

namespace Ui {
    class GMToolsClass: public Ui_GMToolsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GMTOOLS_H
