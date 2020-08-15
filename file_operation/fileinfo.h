#ifndef FILEINFO_H
#define FILEINFO_H

#include <QWidget>

namespace Ui {
class FileInfo;
}

class FileInfo : public QWidget
{
    Q_OBJECT

public:
    explicit FileInfo(QWidget *parent = 0);
    ~FileInfo();

    void getFileInfo(QString &fileName);//获取文件信息
private slots:
    void on_pushButton_clicked();

private:
    Ui::FileInfo *ui;
};

#endif // FILEINFO_H
