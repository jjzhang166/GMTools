/********************************************************************************
** Form generated from reading UI file 'ItemWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ITEMWIDGET_H
#define UI_ITEMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ItemWidget
{
public:
    QGroupBox *groupBox;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;

    void setupUi(QWidget *ItemWidget)
    {
        if (ItemWidget->objectName().isEmpty())
            ItemWidget->setObjectName(QStringLiteral("ItemWidget"));
        ItemWidget->resize(263, 56);
        groupBox = new QGroupBox(ItemWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 251, 50));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 20, 61, 20));
        lineEdit->setEchoMode(QLineEdit::Normal);
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(190, 20, 61, 21));
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(70, 20, 61, 20));
        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(130, 20, 61, 20));

        retranslateUi(ItemWidget);

        QMetaObject::connectSlotsByName(ItemWidget);
    } // setupUi

    void retranslateUi(QWidget *ItemWidget)
    {
        ItemWidget->setWindowTitle(QApplication::translate("ItemWidget", "ItemWidget", 0));
        groupBox->setTitle(QApplication::translate("ItemWidget", "\345\242\236\345\212\240\351\207\221\345\270\201", 0));
        pushButton->setText(QApplication::translate("ItemWidget", "\346\211\247\350\241\214", 0));
    } // retranslateUi

};

namespace Ui {
    class ItemWidget: public Ui_ItemWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ITEMWIDGET_H
