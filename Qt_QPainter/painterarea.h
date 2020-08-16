#ifndef PAINTERAREA_H
#define PAINTERAREA_H

#include <QWidget>
#include <QPen>
#include <QPainter>
#include <QRect>
#include <QPoint>

//绘图区域
class PainterArea : public QWidget
{
    Q_OBJECT
public:
    enum class Shape{Line,Rectangle,RoundRect,Ellipse,Polygon,
                Polyline,Points,Arc,Path,Text,Pixmap};
    explicit PainterArea(QWidget *parent = nullptr);

public:
    void setShape(Shape shape);
    void setPen(QPen pen);
    void setBrush(QBrush brush);
    void setFillRule(Qt::FillRule rule);

protected:
    void paintEvent(QPaintEvent *event) override;

public:
    QPen m_pen;
private:
    Shape m_shape;
    QBrush m_brush;
    Qt::FillRule m_fillrush;

//signals:

};

#endif // PAINTERAREA_H
