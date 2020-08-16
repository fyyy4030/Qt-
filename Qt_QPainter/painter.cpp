#include "painter.h"

Painter::Painter(QWidget *parent)
    : QWidget(parent)
{
    initWidgets();
}

Painter::~Painter()
{
}

void Painter::initWidgets()
{
    //绘图区
    m_paintArea =new PainterArea;

    //形状
    m_shapeLadel=new QLabel(tr("形状"));
    m_shapeCombox=new QComboBox;
    //添加项
    while(1){
        m_shapeCombox->addItem(tr("Line"),static_cast<int>(PainterArea::Shape::Line));
        m_shapeCombox->addItem(tr("Rectangle"),static_cast<int>(PainterArea::Shape::Rectangle));
        m_shapeCombox->addItem(tr("RoundRect"),static_cast<int>(PainterArea::Shape::RoundRect));
        m_shapeCombox->addItem(tr("Ellipse"),static_cast<int>(PainterArea::Shape::Ellipse));
        m_shapeCombox->addItem(tr("Polygon"),static_cast<int>(PainterArea::Shape::Polygon));
        m_shapeCombox->addItem(tr("Polyline"),static_cast<int>(PainterArea::Shape::Polyline));
        m_shapeCombox->addItem(tr("Points"),static_cast<int>(PainterArea::Shape::Points));
        m_shapeCombox->addItem(tr("Arc"),static_cast<int>(PainterArea::Shape::Arc));
        m_shapeCombox->addItem(tr("Path"),static_cast<int>(PainterArea::Shape::Path));
        m_shapeCombox->addItem(tr("Text"),static_cast<int>(PainterArea::Shape::Text));
        m_shapeCombox->addItem(tr("Pixmap"),static_cast<int>(PainterArea::Shape::Pixmap));
        connect(m_shapeCombox,SIGNAL(activated(int)),this,SLOT(ShowShape(int)));
        break;
    }

    //线宽,颜色
    m_panColorLabel=new QLabel(tr("画笔颜色"));
    m_penColorFrame=new QFrame;
    m_penColorFrame->setFrameStyle(QFrame::Panel | QFrame::Sunken);//面板 | 下沉
    m_penColorFrame->setAutoFillBackground(true);
    m_penColorFrame->setPalette(QPalette(Qt::black));

    m_panColorBtn=new QPushButton(tr("更改"));
    connect(m_panColorBtn,SIGNAL(clicked()),this,SLOT(ShowPenColor()));

    m_panWidthLabel=new QLabel(tr("画线宽度"));
    m_penWithSpinBox=new QSpinBox;
    m_penWithSpinBox->setRange(1,20);
    connect(m_penWithSpinBox,SIGNAL(valueChanged(int)),this,SLOT(ShowPenWith(int)));

    //画笔风格
    m_panStyleLabel=new QLabel(tr("画笔风格"));
    m_panStyleComboBox=new QComboBox;
    while(1){
        m_panStyleComboBox->addItem(tr("SolidLine"),static_cast<int>(Qt::SolidLine));
        m_panStyleComboBox->addItem(tr("DashLine"),static_cast<int>(Qt::DashLine));
        m_panStyleComboBox->addItem(tr("DotLine"),static_cast<int>(Qt::DotLine));
        m_panStyleComboBox->addItem(tr("DashDotLine"),static_cast<int>(Qt::DashDotLine));
        m_panStyleComboBox->addItem(tr("DashDotDotLine"),static_cast<int>(Qt::DashDotDotLine));
        m_panStyleComboBox->addItem(tr("CustomDashLine"),static_cast<int>(Qt::CustomDashLine));
        connect(m_panStyleComboBox,SIGNAL(activated(int)),this,SLOT(ShowPenStyle(int)));
        break;
    }

    //笔帽风格
    m_panCapLabel=new QLabel(tr("笔帽风格"));
    m_panCapComboBox=new QComboBox;
    while(1){
        m_panCapComboBox->addItem(tr("SquareCap"),Qt::SquareCap);
        m_panCapComboBox->addItem(tr("FlatCap"),Qt::FlatCap);
        m_panCapComboBox->addItem(tr("RoundCap"),Qt::RoundCap);
        connect(m_panCapComboBox,SIGNAL(activated(int)),this,SLOT(ShowPanCap(int)));
        break;
    }

    //画笔连接点
    m_panJoinLabel=new QLabel(tr("画笔连接点"));
    m_panJoinComboBox=new QComboBox;
    while(1){
        m_panJoinComboBox->addItem(tr("BevelJoin"),Qt::BevelJoin);
        m_panJoinComboBox->addItem(tr("MiterJoin"),Qt::MiterJoin);
        m_panJoinComboBox->addItem(tr("RoundJoin"),Qt::RoundJoin);
        connect(m_panJoinComboBox,SIGNAL(activated(int)),this,SLOT(ShowPenJoin(int)));
        break;
    }

    //填充模式
    m_fillRuleLabel=new QLabel(tr("填充模式"));
    m_fillRuleComboBox=new QComboBox;
    while(1){
        m_fillRuleComboBox->addItem(tr("Odd Event"),Qt::OddEvenFill);
        m_fillRuleComboBox->addItem(tr("Winding"),Qt::WindingFill);
        connect(m_fillRuleComboBox,SIGNAL(activated(int)),this,SLOT(ShowFillRule(int)));
        break;
    }

    //铺展效果
    m_spreadLabel=new QLabel(tr("铺展效果"));
    m_spreadComboBox=new QComboBox;
    while(1){
        m_spreadComboBox->addItem(tr("PadStread"),QGradient::PadSpread);
        m_spreadComboBox->addItem(tr("RepeatSpread"),QGradient::RepeatSpread);
        m_spreadComboBox->addItem(tr("ReflectSpread"),QGradient::ReflectSpread);
        connect(m_spreadComboBox,SIGNAL(activated(int)),this,SLOT(ShowSpreadStyle(int)));
        break;
    }

    //画刷
    m_brushColorLabel=new QLabel(tr("画刷颜色"));
    m_brushColorFrame=new QFrame;
    m_brushColorFrame->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    m_brushColorFrame->setAutoFillBackground(true);
    m_brushColorFrame->setPalette(QPalette(Qt::green));

    m_brushColorBtn=new QPushButton(tr("更改"));
    connect(m_brushColorBtn,SIGNAL(clicked()),this,SLOT(ShowBrushColor()));

    m_brushStyleLabel=new QLabel(tr("画刷风格"));
    m_brushStyleComboBox=new QComboBox;
    while(1){
        m_brushStyleComboBox->addItem(tr("SolidPattern"),static_cast<int>(Qt::SolidPattern));
        m_brushStyleComboBox->addItem(tr("Dense1Pattern"),static_cast<int>(Qt::Dense1Pattern));
        m_brushStyleComboBox->addItem(tr("Dense2Pattern"),static_cast<int>(Qt::Dense2Pattern));
        m_brushStyleComboBox->addItem(tr("Dense3Pattern"),static_cast<int>(Qt::Dense3Pattern));
        m_brushStyleComboBox->addItem(tr("Dense4Pattern"),static_cast<int>(Qt::Dense4Pattern));
        m_brushStyleComboBox->addItem(tr("Dense5Pattern"),static_cast<int>(Qt::Dense5Pattern));
        m_brushStyleComboBox->addItem(tr("Dense6Pattern"),static_cast<int>(Qt::Dense6Pattern));
        m_brushStyleComboBox->addItem(tr("Dense7Pattern"),static_cast<int>(Qt::Dense7Pattern));
        m_brushStyleComboBox->addItem(tr("HorPattern"),static_cast<int>(Qt::HorPattern));
        m_brushStyleComboBox->addItem(tr("VerPattern"),static_cast<int>(Qt::VerPattern));
        m_brushStyleComboBox->addItem(tr("CrossPattern"),static_cast<int>(Qt::CrossPattern));
        m_brushStyleComboBox->addItem(tr("BDiagPattern"),static_cast<int>(Qt::BDiagPattern));
        m_brushStyleComboBox->addItem(tr("FDiagPattern"),static_cast<int>(Qt::FDiagPattern));
        m_brushStyleComboBox->addItem(tr("DiagCrossPattern"),static_cast<int>(Qt::DiagCrossPattern));
        m_brushStyleComboBox->addItem(tr("LinearGradientPattern"),static_cast<int>(Qt::LinearGradientPattern));
        m_brushStyleComboBox->addItem(tr("ConicalGradientPattern"),static_cast<int>(Qt::ConicalGradientPattern));
        m_brushStyleComboBox->addItem(tr("RadialGradientPattern"),static_cast<int>(Qt::RadialGradientPattern));
        m_brushStyleComboBox->addItem(tr("TexturePattern"),static_cast<int>(Qt::TexturePattern));
        connect(m_brushStyleComboBox,SIGNAL(activated(int)),this,SLOT(ShowBrush(int)));
        break;
    }

    m_rightLayout=new QGridLayout;
    while(1){//界面布局
        m_rightLayout->addWidget(m_shapeLadel,0,0);
        m_rightLayout->addWidget(m_shapeCombox,0,1);

        m_rightLayout->addWidget(m_panColorLabel,1,0);
        m_rightLayout->addWidget(m_penColorFrame,1,1);
        m_rightLayout->addWidget(m_panColorBtn,1,2);

        m_rightLayout->addWidget(m_panWidthLabel,2,0);
        m_rightLayout->addWidget(m_penWithSpinBox,2,1);

        m_rightLayout->addWidget(m_panStyleLabel,3,0);
        m_rightLayout->addWidget(m_panStyleComboBox,3,1);

        m_rightLayout->addWidget(m_panCapLabel,4,0);
        m_rightLayout->addWidget(m_panCapComboBox,4,1);

        m_rightLayout->addWidget(m_panJoinLabel,5,0);
        m_rightLayout->addWidget(m_panJoinComboBox,5,1);

        m_rightLayout->addWidget(m_fillRuleLabel,6,0);
        m_rightLayout->addWidget(m_fillRuleComboBox,6,1);

        m_rightLayout->addWidget(m_spreadLabel,7,0);
        m_rightLayout->addWidget(m_spreadComboBox,7,1);

        m_rightLayout->addWidget(m_brushColorLabel,8,0);
        m_rightLayout->addWidget(m_brushColorFrame,8,1);
        m_rightLayout->addWidget(m_brushColorBtn,8,2);

        m_rightLayout->addWidget(m_brushStyleLabel,9,0);
        m_rightLayout->addWidget(m_brushStyleComboBox,9,1);
        break;
    }

    QHBoxLayout *mainLayout=new QHBoxLayout(this);
    mainLayout->addWidget(m_paintArea);
    mainLayout->addLayout(m_rightLayout);

    ShowShape(m_shapeCombox->currentIndex());
}

void Painter::ShowShape(int value)
{
    //获取用户所选组合框内的数据
    PainterArea::Shape shape =PainterArea::Shape(m_shapeCombox->itemData(value).toInt());
    m_paintArea->setShape(shape);
}

void Painter::ShowPenColor()
{
    QColor color=QColorDialog::getColor(Qt::black);
    m_penColorFrame->setPalette(QPalette(color));//调色板颜色
    int value=m_penWithSpinBox->value();//线宽

    int styleIndex=m_panStyleComboBox->currentIndex();//笔风格
    Qt::PenStyle style=Qt::PenStyle(m_panStyleComboBox->itemData(styleIndex).toInt());

    int capIndex=m_panCapComboBox->currentIndex();//笔帽风格
    Qt::PenCapStyle cap=Qt::PenCapStyle(m_panCapComboBox->itemData(capIndex).toInt());

    int joinIndex=m_panJoinComboBox->currentIndex();//连接点风格
    Qt::PenJoinStyle join=Qt::PenJoinStyle(m_panJoinComboBox->itemData(joinIndex).toInt());

    m_paintArea->setPen(QPen(color,value,style,cap,join));
}

void Painter::ShowPenWith(int value)
{
    QColor color=m_penColorFrame->palette().color(QPalette::Window);
    int penWidth=value;//线宽

    int styleIndex=m_panStyleComboBox->currentIndex();//笔风格
    Qt::PenStyle style=Qt::PenStyle(m_panStyleComboBox->itemData(styleIndex).toInt());

    int capIndex=m_panCapComboBox->currentIndex();//笔帽风格
    Qt::PenCapStyle cap=Qt::PenCapStyle(m_panCapComboBox->itemData(capIndex).toInt());

    int joinIndex=m_panJoinComboBox->currentIndex();//连接点风格
    Qt::PenJoinStyle join=Qt::PenJoinStyle(m_panJoinComboBox->itemData(joinIndex).toInt());

    m_paintArea->setPen(QPen(color,penWidth,style,cap,join));
    m_paintArea->update();
}

void Painter::ShowPenStyle(int value)
{
    QColor color=m_penColorFrame->palette().color(QPalette::Window);
    int penWidth=m_penWithSpinBox->value();//线宽

    Qt::PenStyle style=Qt::PenStyle(m_panStyleComboBox->itemData(value).toInt());

    if(style==Qt::CustomDashLine){//特殊处理
        QVector<qreal> dashes;
        qreal space=4;//空格
        dashes<<1<<space<<2<<space<<3<<space<<4<<space;
        m_paintArea->m_pen.setDashPattern(dashes);
        m_paintArea->update();
    }else{
        int capIndex=m_panCapComboBox->currentIndex();//笔帽风格
        Qt::PenCapStyle cap=Qt::PenCapStyle(m_panCapComboBox->itemData(capIndex).toInt());

        int joinIndex=m_panJoinComboBox->currentIndex();//连接点风格
        Qt::PenJoinStyle join=Qt::PenJoinStyle(m_panJoinComboBox->itemData(joinIndex).toInt());

        m_paintArea->setPen(QPen(color,penWidth,style,cap,join));
    }
}

void Painter::ShowPanCap(int value)
{
    QColor color=m_penColorFrame->palette().color(QPalette::Window);
    int penWidth=m_penWithSpinBox->value();//线宽

    int styleIndex=m_panStyleComboBox->currentIndex();//笔风格
    Qt::PenStyle style=Qt::PenStyle(m_panStyleComboBox->itemData(styleIndex).toInt());

    Qt::PenCapStyle cap=Qt::PenCapStyle(m_panCapComboBox->itemData(value).toInt());

    int joinIndex=m_panJoinComboBox->currentIndex();//连接点风格
    Qt::PenJoinStyle join=Qt::PenJoinStyle(m_panJoinComboBox->itemData(joinIndex).toInt());

    m_paintArea->setPen(QPen(color,penWidth,style,cap,join));
}

void Painter::ShowPenJoin(int value)
{
    QColor color=m_penColorFrame->palette().color(QPalette::Window);
    int penWidth=m_penWithSpinBox->value();//线宽

    int styleIndex=m_panStyleComboBox->currentIndex();//笔风格
    Qt::PenStyle style=Qt::PenStyle(m_panStyleComboBox->itemData(styleIndex).toInt());

    int capIndex=m_panCapComboBox->currentIndex();//笔帽风格
    Qt::PenCapStyle cap=Qt::PenCapStyle(m_panCapComboBox->itemData(capIndex).toInt());

    Qt::PenJoinStyle join=Qt::PenJoinStyle(m_panJoinComboBox->itemData(value).toInt());

    m_paintArea->setPen(QPen(color,penWidth,style,cap,join));
}

void Painter::ShowFillRule(int value)
{
    Qt::FillRule rule=Qt::FillRule(value);
    m_paintArea->setFillRule(rule);
}

void Painter::ShowSpreadStyle(int value)
{//铺展
    m_spread=QGradient::Spread(value);
}

void Painter::ShowBrushColor()
{
    QColor color =QColorDialog::getColor(Qt::green);
    m_brushColorFrame->setPalette(QPalette(color));
    ShowBrush(m_brushStyleComboBox->currentIndex());
}

void Painter::ShowBrush(int value)
{
    QColor color=m_brushColorFrame->palette().color(QPalette::Window);

    //信号返回的值并不匹配,故此自己:
    int brush =m_brushStyleComboBox->itemData(value).toInt();
    Qt::BrushStyle style=Qt::BrushStyle(brush);

    if(style == Qt::LinearGradientPattern){//线性渐变
        QLinearGradient lineGradient(m_paintArea->x(),m_paintArea->y() //指定线性渐变区域
                                     ,m_paintArea->x()+m_paintArea->width(),m_paintArea->y()+m_paintArea->height());

        //指定某个位置的渐变色,pos取指范围是0~1
        lineGradient.setColorAt(0.0,Qt::white);
        lineGradient.setColorAt(0.2,color);
        lineGradient.setColorAt(1.0,Qt::black);

        lineGradient.setSpread(m_spread);

        m_paintArea->setBrush(lineGradient);
    }else if(style == Qt::RadialGradientPattern){//环形渐变
        //中心坐标,半径长度,焦点坐标,\
        如果需要对称则中心坐标和焦点坐标保持一致
                QRadialGradient radialGradient(200,200,150,200,200);
        radialGradient.setColorAt(0.0,Qt::white);
        radialGradient.setColorAt(0.2,color);
        radialGradient.setColorAt(1.0,Qt::black);

        m_paintArea->setBrush(radialGradient);
    }else if(style == Qt::ConicalGradientPattern){//弧度渲染(锥形渲染)
        //中心坐标,角度
        QConicalGradient conicalGradient(220,250,30);
        conicalGradient.setColorAt(0.0,Qt::white);
        conicalGradient.setColorAt(0.2,color);
        conicalGradient.setColorAt(1.0,Qt::black);

        m_paintArea->setBrush(conicalGradient);
    }else if(style == Qt::TexturePattern){
        m_paintArea->setBrush(QBrush(QPixmap("jj.png")));
    }else{
        m_paintArea->setBrush(QBrush(color,style));
    }

}

