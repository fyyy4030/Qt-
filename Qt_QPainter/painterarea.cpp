#include "painterarea.h"

PainterArea::PainterArea(QWidget *parent) : QWidget(parent)
{
    setPalette(Qt::white);//设置调色板
    setAutoFillBackground(true);
    setFixedSize(600,600);
}

void PainterArea::setShape(PainterArea::Shape shape)
{
    m_shape=shape;
    update();
}

void PainterArea::setPen(QPen pen)
{
    m_pen=pen;
    update();
}

void PainterArea::setBrush(QBrush brush)
{
    m_brush=brush;
    update();
}

void PainterArea::setFillRule(Qt::FillRule rule)
{
    m_fillrush=rule;
    update();
}

void PainterArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(m_pen);
    painter.setBrush(m_brush);

    QRect rect(50,100,400,300);//矩形
    static const QPoint points[4]={
        QPoint(150,100),
        QPoint(300,150),
        QPoint(350,250),
        QPoint(100,300)};//坐标

    /*注意:用QPainter画弧度所使用的角度值，是以1/16°为单位的，在画弧度的时候1°用16表示。
    另QPainter::drawPixmap()可直接将图片画到部件上。
    兼容模式QPainter:.CompositionMode */
    int startAngle=30*16;
    int spanAngle=120*16;

    QPainterPath path;//路径
    path.addRect(150,150,100,100);
    path.moveTo(100,200);
    path.cubicTo(300,100,200,200,300,300);
    path.cubicTo(100,300,200,200,100,100);
    path.setFillRule(m_fillrush);//设置填充规则

    switch(m_shape){//根据传值画形状
    case Shape::Line:
        //painter.drawLine(rect.topLeft(),rect.topRight());//画线(左上角开始画,右下角结束)
        painter.drawLine(rect.x(),rect.y(),rect.x()+rect.width(),rect.y()+rect.height());
        break;
    case Shape::Rectangle:
        painter.drawRect(rect);
        break;
    case Shape::RoundRect:
        painter.drawRoundRect(rect);
        break;
    case Shape::Ellipse:
        painter.drawEllipse(rect);
        break;
    case Shape::Polygon:
        painter.drawPolygon(points,4);
        break;
    case Shape::Polyline:
        painter.drawPolyline(points,4);
        break;
    case Shape::Points:
        painter.drawPoints(points,4);
        break;
    case Shape::Arc:
        painter.drawArc(rect,startAngle,spanAngle);
        break;
    case Shape::Path:
        painter.drawPath(path);
        break;
    case Shape::Text:
        painter.drawText(rect,Qt::AlignCenter,tr("How Are You"));
        break;
    case Shape::Pixmap:
        painter.drawPixmap(50,100,QPixmap("jj.png"));
        break;
    default:
        break;
    }
}
