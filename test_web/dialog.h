#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtWebEngineWidgets/QWebEngineView>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

    void show();
private:
    Ui::Dialog *ui;

    QWebEngineView* m_webView;


};

#endif // DIALOG_H
