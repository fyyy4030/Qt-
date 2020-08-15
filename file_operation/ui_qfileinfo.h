/********************************************************************************
** Form generated from reading UI file 'qfileinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QFILEINFO_H
#define UI_QFILEINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QFileInfo
{
public:
    QPushButton *pushButton;
    QWidget *widget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *filename;
    QLineEdit *filesize;
    QLineEdit *begintime;
    QLineEdit *amendtime;
    QLineEdit *endtime;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout;
    QCheckBox *catalog;
    QCheckBox *file;
    QCheckBox *symbol;
    QCheckBox *hide;
    QCheckBox *read;
    QCheckBox *write;
    QCheckBox *write_2;
    QLabel *label_6;

    void setupUi(QWidget *QFileInfo)
    {
        if (QFileInfo->objectName().isEmpty())
            QFileInfo->setObjectName(QStringLiteral("QFileInfo"));
        QFileInfo->resize(441, 217);
        pushButton = new QPushButton(QFileInfo);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(400, 12, 31, 20));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        widget = new QWidget(QFileInfo);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 383, 198));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(10);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        filename = new QLineEdit(widget);
        filename->setObjectName(QStringLiteral("filename"));
        sizePolicy.setHeightForWidth(filename->sizePolicy().hasHeightForWidth());
        filename->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(filename);

        filesize = new QLineEdit(widget);
        filesize->setObjectName(QStringLiteral("filesize"));

        verticalLayout_2->addWidget(filesize);

        begintime = new QLineEdit(widget);
        begintime->setObjectName(QStringLiteral("begintime"));

        verticalLayout_2->addWidget(begintime);

        amendtime = new QLineEdit(widget);
        amendtime->setObjectName(QStringLiteral("amendtime"));

        verticalLayout_2->addWidget(amendtime);

        endtime = new QLineEdit(widget);
        endtime->setObjectName(QStringLiteral("endtime"));

        verticalLayout_2->addWidget(endtime);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        catalog = new QCheckBox(widget);
        catalog->setObjectName(QStringLiteral("catalog"));

        horizontalLayout->addWidget(catalog);

        file = new QCheckBox(widget);
        file->setObjectName(QStringLiteral("file"));

        horizontalLayout->addWidget(file);

        symbol = new QCheckBox(widget);
        symbol->setObjectName(QStringLiteral("symbol"));

        horizontalLayout->addWidget(symbol);

        hide = new QCheckBox(widget);
        hide->setObjectName(QStringLiteral("hide"));

        horizontalLayout->addWidget(hide);

        read = new QCheckBox(widget);
        read->setObjectName(QStringLiteral("read"));

        horizontalLayout->addWidget(read);

        write = new QCheckBox(widget);
        write->setObjectName(QStringLiteral("write"));

        horizontalLayout->addWidget(write);

        write_2 = new QCheckBox(widget);
        write_2->setObjectName(QStringLiteral("write_2"));

        horizontalLayout->addWidget(write_2);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 2);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 1, 0, 1, 1);


        retranslateUi(QFileInfo);

        QMetaObject::connectSlotsByName(QFileInfo);
    } // setupUi

    void retranslateUi(QWidget *QFileInfo)
    {
        QFileInfo->setWindowTitle(QApplication::translate("QFileInfo", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("QFileInfo", "...", Q_NULLPTR));
        label->setText(QApplication::translate("QFileInfo", "\346\226\207\344\273\266\345\220\215:", Q_NULLPTR));
        label_2->setText(QApplication::translate("QFileInfo", "\346\226\207\344\273\266\345\244\247\345\260\217:", Q_NULLPTR));
        label_3->setText(QApplication::translate("QFileInfo", "\345\210\233\345\273\272\346\227\266\351\227\264:", Q_NULLPTR));
        label_4->setText(QApplication::translate("QFileInfo", "\346\234\200\345\220\216\344\277\256\346\224\271\346\227\266\351\227\264:", Q_NULLPTR));
        label_5->setText(QApplication::translate("QFileInfo", "\346\234\200\345\220\216\350\256\277\351\227\256\346\227\266\351\227\264:", Q_NULLPTR));
        catalog->setText(QApplication::translate("QFileInfo", "\347\233\256\345\275\225", Q_NULLPTR));
        file->setText(QApplication::translate("QFileInfo", "\346\226\207\344\273\266", Q_NULLPTR));
        symbol->setText(QApplication::translate("QFileInfo", "\347\254\246\345\217\267\351\223\276\346\216\245", Q_NULLPTR));
        hide->setText(QApplication::translate("QFileInfo", "\351\232\220\350\227\217", Q_NULLPTR));
        read->setText(QApplication::translate("QFileInfo", "\350\257\273", Q_NULLPTR));
        write->setText(QApplication::translate("QFileInfo", "\345\206\231", Q_NULLPTR));
        write_2->setText(QApplication::translate("QFileInfo", "\346\211\247\350\241\214", Q_NULLPTR));
        label_6->setText(QApplication::translate("QFileInfo", "\345\261\236\346\200\247:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QFileInfo: public Ui_QFileInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QFILEINFO_H
