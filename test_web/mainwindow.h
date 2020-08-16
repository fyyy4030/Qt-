#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWebEngineWidgets/QWebEngineView>
#include "dialog.h"
#include "jscontext.h"
#include <QWebChannel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void onAdd();
private:
    Ui::MainWindow *ui;
    QWebEngineView* m_webView;
    Dialog* m_inspector;

    JsContext* m_jsContext;
    QWebChannel* m_webChannel;
};
#endif // MAINWINDOW_H
