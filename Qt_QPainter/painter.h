#ifndef PAINTER_H
#define PAINTER_H

#include <QWidget>
#include "painterarea.h"
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include <QGridLayout>
#include <QPainter>
#include <QDebug>
#include <QColorDialog>

//绘图操作区
class Painter : public QWidget
{
    Q_OBJECT

public:
    Painter(QWidget *parent = nullptr);
    ~Painter();

    void initWidgets();

private slots:
    void ShowShape(int value);
    void ShowPenColor();
    void ShowPenWith(int value);
    void ShowPenStyle(int value);
    void ShowPanCap(int value);
    void ShowPenJoin(int value);
    void ShowFillRule(int value);
    void ShowSpreadStyle(int value);
    void ShowBrushColor();
    void ShowBrush(int value);
private:
    //绘图区
    PainterArea *m_paintArea;
    //形状
    QLabel *m_shapeLadel;
    QComboBox *m_shapeCombox;
    //线宽,颜色
    QLabel *m_panWidthLabel;
    QLabel *m_panColorLabel;
    QFrame *m_penColorFrame;
    QPushButton *m_panColorBtn;
    QSpinBox *m_penWithSpinBox;
    //画笔风格
    QLabel *m_panStyleLabel;
    QComboBox *m_panStyleComboBox;
    //笔帽风格
    QLabel *m_panCapLabel;
    QComboBox *m_panCapComboBox;
    //画笔连接点
    QLabel *m_panJoinLabel;
    QComboBox *m_panJoinComboBox;
    //填充模式
    QLabel *m_fillRuleLabel;
    QComboBox *m_fillRuleComboBox;
    //铺展效果
    QLabel *m_spreadLabel;
    QComboBox *m_spreadComboBox;
    QGradient::Spread m_spread;
    //画刷
    QLabel *m_brushColorLabel;
    QFrame *m_brushColorFrame;
    QPushButton *m_brushColorBtn;
    QLabel *m_brushStyleLabel;
    QComboBox *m_brushStyleComboBox;

    QGridLayout *m_rightLayout;

};
#endif // PAINTER_H
