/********************************************************************************
** Form generated from reading UI file 'fileinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEINFO_H
#define UI_FILEINFO_H

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

class Ui_FileInfo
{
public:
    QPushButton *pushButton;
    QWidget *layoutWidget;
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

    void setupUi(QWidget *FileInfo)
    {
        if (FileInfo->objectName().isEmpty())
            FileInfo->setObjectName(QStringLiteral("FileInfo"));
        FileInfo->resize(446, 220);
        pushButton = new QPushButton(FileInfo);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(410, 10, 31, 20));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        layoutWidget = new QWidget(FileInfo);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 391, 201));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(10);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        filename = new QLineEdit(layoutWidget);
        filename->setObjectName(QStringLiteral("filename"));
        sizePolicy.setHeightForWidth(filename->sizePolicy().hasHeightForWidth());
        filename->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(filename);

        filesize = new QLineEdit(layoutWidget);
        filesize->setObjectName(QStringLiteral("filesize"));

        verticalLayout_2->addWidget(filesize);

        begintime = new QLineEdit(layoutWidget);
        begintime->setObjectName(QStringLiteral("begintime"));

        verticalLayout_2->addWidget(begintime);

        amendtime = new QLineEdit(layoutWidget);
        amendtime->setObjectName(QStringLiteral("amendtime"));

        verticalLayout_2->addWidget(amendtime);

        endtime = new QLineEdit(layoutWidget);
        endtime->setObjectName(QStringLiteral("endtime"));

        verticalLayout_2->addWidget(endtime);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        catalog = new QCheckBox(layoutWidget);
        catalog->setObjectName(QStringLiteral("catalog"));

        horizontalLayout->addWidget(catalog);

        file = new QCheckBox(layoutWidget);
        file->setObjectName(QStringLiteral("file"));

        horizontalLayout->addWidget(file);

        symbol = new QCheckBox(layoutWidget);
        symbol->setObjectName(QStringLiteral("symbol"));

        horizontalLayout->addWidget(symbol);

        hide = new QCheckBox(layoutWidget);
        hide->setObjectName(QStringLiteral("hide"));

        horizontalLayout->addWidget(hide);

        read = new QCheckBox(layoutWidget);
        read->setObjectName(QStringLiteral("read"));

        horizontalLayout->addWidget(read);

        write = new QCheckBox(layoutWidget);
        write->setObjectName(QStringLiteral("write"));

        horizontalLayout->addWidget(write);

        write_2 = new QCheckBox(layoutWidget);
        write_2->setObjectName(QStringLiteral("write_2"));

        horizontalLayout->addWidget(write_2);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 2);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 1, 0, 1, 1);


        retranslateUi(FileInfo);

        QMetaObject::connectSlotsByName(FileInfo);
    } // setupUi

    void retranslateUi(QWidget *FileInfo)
    {
        FileInfo->setWindowTitle(QApplication::translate("FileInfo", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("FileInfo", "...", Q_NULLPTR));
        label->setText(QApplication::translate("FileInfo", "\346\226\207\344\273\266\345\220\215:", Q_NULLPTR));
        label_2->setText(QApplication::translate("FileInfo", "\346\226\207\344\273\266\345\244\247\345\260\217:", Q_NULLPTR));
        label_3->setText(QApplication::translate("FileInfo", "\345\210\233\345\273\272\346\227\266\351\227\264:", Q_NULLPTR));
        label_4->setText(QApplication::translate("FileInfo", "\346\234\200\345\220\216\344\277\256\346\224\271\346\227\266\351\227\264:", Q_NULLPTR));
        label_5->setText(QApplication::translate("FileInfo", "\346\234\200\345\220\216\350\256\277\351\227\256\346\227\266\351\227\264:", Q_NULLPTR));
        catalog->setText(QApplication::translate("FileInfo", "\347\233\256\345\275\225", Q_NULLPTR));
        file->setText(QApplication::translate("FileInfo", "\346\226\207\344\273\266", Q_NULLPTR));
        symbol->setText(QApplication::translate("FileInfo", "\347\254\246\345\217\267\351\223\276\346\216\245", Q_NULLPTR));
        hide->setText(QApplication::translate("FileInfo", "\351\232\220\350\227\217", Q_NULLPTR));
        read->setText(QApplication::translate("FileInfo", "\350\257\273", Q_NULLPTR));
        write->setText(QApplication::translate("FileInfo", "\345\206\231", Q_NULLPTR));
        write_2->setText(QApplication::translate("FileInfo", "\346\211\247\350\241\214", Q_NULLPTR));
        label_6->setText(QApplication::translate("FileInfo", "\345\261\236\346\200\247:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FileInfo: public Ui_FileInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEINFO_H
