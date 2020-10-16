#include <QStyleOption>
#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QDebug>
#include <QRandomGenerator>

#include "widgets/graphwidget.h"
#include "edge.h"
#include "node.h"
#include "model/imp/binarytreenode.h"

QGraphicsScene* Node::scene = nullptr;

void Node::setScene(QGraphicsScene *pscene)
{
    scene = pscene;
}

void Node::setParent(ModelItem *pparent)
{
    qreal shift = 200;

    int x,y;

    if (value < pparent->value)
        x = pparent->coordinate->x() - (shift/level);
    if (this->value >= pparent->value)
        x = pparent->coordinate->x() + (shift/level);

    y = pparent->coordinate->y() + height;

    if (coordinate)
        delete coordinate;
    coordinate = new QPointF(x,y);
    scene->addItem(new Edge(this, static_cast<Node*>(pparent)));

    startAnimation();
}

void Node::addItem(ModelItem *pitem)
{

}

void Node::removeItem()
{

}

Node::Node(int val)
    : label(QString::number(val)), width(40), height(40)
{
    value = val;
    background = Qt::green;
//    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(DeviceCoordinateCache);
    setAcceptHoverEvents(true);
    setZValue(1);

    scene->addItem(this);

    coordinate = new QPointF(0, -200);

    moveAnimation = new QPropertyAnimation(this, "pos");
    moveAnimation->setDuration(1000);

    scaleAnimation = new QPropertyAnimation(this, "scale");
    scaleAnimation->setEasingCurve(QEasingCurve::Type::OutCubic);
    scaleAnimation->setDuration(1000);
    scaleAnimation->setStartValue(3);
    scaleAnimation->setEndValue(1);
    scaleAnimation->start();

    connect(moveAnimation, &QAbstractAnimation::finished, [=](){
        for (auto *item : edgeList)
            item->setVisible(true);
        this->background = Qt::white;
    });
}

void Node::startAnimation()
{
    moveAnimation->setKeyValueAt(0, QPointF(0, 0));
    moveAnimation->setKeyValueAt(0.9, QPointF(0, 0));
    moveAnimation->setKeyValueAt(1, *coordinate);
    moveAnimation->setEasingCurve(QEasingCurve::Type::OutCirc);
    moveAnimation->start();
}

void Node::addEdge(Edge *edge)
{
    edgeList << edge;
    edge->adjust();
}

QVector<Edge *> Node::edges() const
{
    return edgeList;
}

QRectF Node::boundingRect() const
{
    qreal adjust = 2;
    return QRectF( -(width/2) - adjust, -(height/2) - adjust, (width+3) + adjust, (height+3) + adjust);
}

QPainterPath Node::shape() const
{
    QPainterPath path;
    path.addEllipse(-(width/2), -(height/2), width, height);
    return path;
}

void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
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

QVariant Node::itemChange(GraphicsItemChange change, const QVariant &value)
{
    switch (change) {
    case ItemPositionHasChanged:
        for (Edge *edge : qAsConst(edgeList))
            edge->adjust();
//        graph->itemMoved();
        break;
    default:
        break;
    };

    return QGraphicsItem::itemChange(change, value);
}

void Node::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mousePressEvent(event);
}

void Node::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}
