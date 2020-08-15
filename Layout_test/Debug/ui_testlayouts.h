/********************************************************************************
** Form generated from reading UI file 'testlayouts.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTLAYOUTS_H
#define UI_TESTLAYOUTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_testLayouts
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *testLayouts)
    {
        if (testLayouts->objectName().isEmpty())
            testLayouts->setObjectName(QStringLiteral("testLayouts"));
        testLayouts->resize(407, 235);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(testLayouts->sizePolicy().hasHeightForWidth());
        testLayouts->setSizePolicy(sizePolicy);
        testLayouts->setAcceptDrops(false);
        gridLayout_2 = new QGridLayout(testLayouts);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(testLayouts);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(testLayouts);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(lineEdit);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(testLayouts);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(label_2);

        lineEdit_2 = new QLineEdit(testLayouts);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        sizePolicy2.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(lineEdit_2);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(testLayouts);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(label_3);

        lineEdit_3 = new QLineEdit(testLayouts);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        sizePolicy2.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy2);

        horizontalLayout_4->addWidget(lineEdit_3);


        gridLayout->addLayout(horizontalLayout_4, 2, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_4 = new QLabel(testLayouts);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(label_4);

        lineEdit_4 = new QLineEdit(testLayouts);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lineEdit_4->sizePolicy().hasHeightForWidth());
        lineEdit_4->setSizePolicy(sizePolicy3);
        lineEdit_4->setBaseSize(QSize(179, 10));

        horizontalLayout_5->addWidget(lineEdit_4);


        gridLayout->addLayout(horizontalLayout_5, 3, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_5 = new QLabel(testLayouts);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(label_5);

        radioButton = new QRadioButton(testLayouts);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        sizePolicy1.setHeightForWidth(radioButton->sizePolicy().hasHeightForWidth());
        radioButton->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(radioButton);

        radioButton_2 = new QRadioButton(testLayouts);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        sizePolicy1.setHeightForWidth(radioButton_2->sizePolicy().hasHeightForWidth());
        radioButton_2->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(radioButton_2);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout_6, 4, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(lineEdit);
        label_2->setBuddy(lineEdit_2);
        label_3->setBuddy(lineEdit_3);
#endif // QT_NO_SHORTCUT

        retranslateUi(testLayouts);

        QMetaObject::connectSlotsByName(testLayouts);
    } // setupUi

    void retranslateUi(QWidget *testLayouts)
    {
        testLayouts->setWindowTitle(QApplication::translate("testLayouts", "testLayouts", Q_NULLPTR));
        label->setText(QApplication::translate("testLayouts", "\345\247\223\345\220\215: (&N)", Q_NULLPTR));
        label_2->setText(QApplication::translate("testLayouts", "\345\271\264\351\276\204: (&A)", Q_NULLPTR));
        label_3->setText(QApplication::translate("testLayouts", "\351\202\256\347\256\261: (&E)", Q_NULLPTR));
        label_4->setText(QApplication::translate("testLayouts", "\351\227\250\347\211\214\345\217\267\347\240\201:", Q_NULLPTR));
        label_5->setText(QApplication::translate("testLayouts", "\346\200\247\345\210\253:", Q_NULLPTR));
        radioButton->setText(QApplication::translate("testLayouts", "\347\224\267", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("testLayouts", "\345\245\263", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class testLayouts: public Ui_testLayouts {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTLAYOUTS_H
