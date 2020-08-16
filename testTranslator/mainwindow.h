#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QComboBox>
#include <QLabel>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void changLanguage(int index);

private:
    QComboBox* m_languageBox;//多语言选择
    QLabel* m_nameLabel;
    QLabel* m_signLabel;
};
#endif // MAINWINDOW_H
