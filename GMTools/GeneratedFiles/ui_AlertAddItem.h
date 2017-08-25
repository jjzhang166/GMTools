/********************************************************************************
** Form generated from reading UI file 'AlertAddItem.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALERTADDITEM_H
#define UI_ALERTADDITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AlertAddItem
{
public:
    QPushButton *alert_btn_ok;
    QGroupBox *groupBox;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *ed_01;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *ed_02;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QLineEdit *ed_03;

    void setupUi(QWidget *AlertAddItem)
    {
        if (AlertAddItem->objectName().isEmpty())
            AlertAddItem->setObjectName(QStringLiteral("AlertAddItem"));
        AlertAddItem->resize(462, 200);
        alert_btn_ok = new QPushButton(AlertAddItem);
        alert_btn_ok->setObjectName(QStringLiteral("alert_btn_ok"));
        alert_btn_ok->setGeometry(QRect(169, 140, 121, 41));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(alert_btn_ok->sizePolicy().hasHeightForWidth());
        alert_btn_ok->setSizePolicy(sizePolicy);
        groupBox = new QGroupBox(AlertAddItem);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 20, 444, 80));
        groupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        groupBox->setFlat(false);
        widget = new QWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 30, 419, 42));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        ed_01 = new QLineEdit(widget);
        ed_01->setObjectName(QStringLiteral("ed_01"));

        verticalLayout->addWidget(ed_01);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        ed_02 = new QLineEdit(widget);
        ed_02->setObjectName(QStringLiteral("ed_02"));

        verticalLayout_2->addWidget(ed_02);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_4->addWidget(label_4);

        ed_03 = new QLineEdit(widget);
        ed_03->setObjectName(QStringLiteral("ed_03"));

        verticalLayout_4->addWidget(ed_03);


        horizontalLayout->addLayout(verticalLayout_4);


        retranslateUi(AlertAddItem);

        QMetaObject::connectSlotsByName(AlertAddItem);
    } // setupUi

    void retranslateUi(QWidget *AlertAddItem)
    {
        AlertAddItem->setWindowTitle(QApplication::translate("AlertAddItem", "AlertAddItem", 0));
        alert_btn_ok->setText(QApplication::translate("AlertAddItem", "\347\241\256\345\256\232", 0));
        groupBox->setTitle(QApplication::translate("AlertAddItem", "\345\242\236\345\212\240\346\214\207\344\273\244", 0));
        label->setText(QApplication::translate("AlertAddItem", "\346\214\207\344\273\244\345\244\264\357\274\232", 0));
        label_2->setText(QApplication::translate("AlertAddItem", "\345\217\202\346\225\260\345\244\207\346\263\250\357\274\232", 0));
        label_4->setText(QApplication::translate("AlertAddItem", "\345\217\202\346\225\260\345\244\207\346\263\250\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class AlertAddItem: public Ui_AlertAddItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALERTADDITEM_H
