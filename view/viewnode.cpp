#include <QStyleOption>
#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QDebug>
#include <QRandomGenerator>

#include "viewnode.h"
#include "widgets/graphwidget.h"
#include "view.h"
#include "model/model.h"

ViewNode::ViewNode(int val, GraphWidget* pwidget)
    : label(QString::number(val)), graph(pwidget), width(40), height(40)
{
    background = Qt::green;
//    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(DeviceCoordinateCache);
    setAcceptHoverEvents(true);
    setZValue(1);

    graph->scene()->addItem(this);
    hardX = 0;
    hardY = -200;

    animation = new QPropertyAnimation(this, "pos");
    animation->setDuration(1000);

    scaleAnimation = new QPropertyAnimation(this, "scale");
    scaleAnimation->setEasingCurve(QEasingCurve::Type::OutCubic);
    scaleAnimation->setDuration(1000);
    scaleAnimation->setStartValue(3);
    scaleAnimation->setEndValue(1);
    scaleAnimation->start();


    connect(animation, &QAbstractAnimation::finished, [=](){
        this->edgeList.at(0)->setVisible(true);
        this->background = Qt::white;
    });
}

void ViewNode::startAnimation()
{
    animation->setKeyValueAt(0, QPointF(0, 0));
    animation->setKeyValueAt(0.9, QPointF(0, 0));
    animation->setKeyValueAt(1, QPointF(hardX, hardY));
    animation->setEasingCurve(QEasingCurve::Type::OutCirc);
    animation->start();
}

void ViewNode::addEdge(ViewEdge *edge)
{
    edgeList << edge;
    edge->adjust();
}

QVector<ViewEdge *> ViewNode::edges() const
{
    return edgeList;
}

QRectF ViewNode::boundingRect() const
{
    qreal adjust = 2;
    return QRectF( -(width/2) - adjust, -(height/2) - adjust, (width+3) + adjust, (height+3) + adjust);
}

QPainterPath ViewNode::shape() const
{
    QPainterPath path;
    path.addEllipse(-(width/2), -(height/2), width, height);
    return path;
}

void ViewNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    // Shadow
//    painter->setPen(Qt::NoPen);
//    painter->setBrush(Qt::darkGray);
//    painter->drawEllipse(-10, -10, 25, 25);

    // Backgound
    if (option->state & QStyle::State_Sunken)
        painter->setBrush(Qt::red);
    else
        painter->setBrush(background);

    // Border
    painter->setPen(QPen(Qt::black, 0));
    painter->drawEllipse(-(width/2), -(height/2), width, height);

    // Print Font Text
    QFont number = painter->font();
    number.setBold(true);
    number.setPointSize(12);
    number.setHintingPreference(QFont::PreferFullHinting);
    painter->setFont(number);
    painter->setPen(Qt::black);
    painter->drawText(this->boundingRect(),Qt::AlignCenter, label);
    //
}

void ViewNode::addToGraph(QGraphicsItem *item)
{
    graph->scene()->addItem(item);
}

QVariant ViewNode::itemChange(GraphicsItemChange change, const QVariant &value)
{
    switch (change) {
    case ItemPositionHasChanged:
        for (ViewEdge *edge : qAsConst(edgeList))
            edge->adjust();
//        graph->itemMoved();
        break;
    default:
        break;
    };

    return QGraphicsItem::itemChange(change, value);
}

void ViewNode::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mousePressEvent(event);
}

void ViewNode::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}
