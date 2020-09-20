#include "edge.h"
#include "viewnode.h"
#include "graphwidget.h"

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOption>

//! [0]
ViewNode::ViewNode(GraphWidget *graphWidget, QString &l)
    : label(l), graph(graphWidget)
{
    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(DeviceCoordinateCache);
    setAcceptHoverEvents(true);
    setZValue(-1);
    width = 100;
    height = 60;
}
//! [0]

//! [1]
void ViewNode::addEdge(ViewEdge *edge)
{
    edgeList << edge;
    edge->adjust();
}

QVector<ViewEdge *> ViewNode::edges() const
{
    return edgeList;
}
//! [1]

//! [2]
void ViewNode::calculateForces()
{
    if (!scene() || scene()->mouseGrabberItem() == this) {
        newPos = pos();
        return;
    }
//! [2]

//! [3]
    // Sum up all forces pushing this item away
    qreal xvel = 0;
    qreal yvel = 0;
    const QList<QGraphicsItem *> items = scene()->items();
    for (QGraphicsItem *item : items) {
        ViewNode *node = qgraphicsitem_cast<ViewNode *>(item);
        if (!node)
            continue;

        QPointF vec = mapToItem(node, 0, 0);
        qreal dx = vec.x();
        qreal dy = vec.y();
        double l = 2.0 * (dx * dx + dy * dy);
        if (l > 0) {
            xvel += (dx * 150.0) / l;
            yvel += (dy * 150.0) / l;
        }
    }
//! [3]

//! [4]
    // Now subtract all forces pulling items together
    double weight = (edgeList.size() + 1) * 10;
    for (const ViewEdge *edge : qAsConst(edgeList)) {
        QPointF vec;
        if (edge->sourceNode() == this)
            vec = mapToItem(edge->destNode(), 0, 0);
        else
            vec = mapToItem(edge->sourceNode(), 0, 0);
        xvel -= vec.x() / weight;
        yvel -= vec.y() / weight;
    }
//! [4]

//! [5]
    if (qAbs(xvel) < 0.1 && qAbs(yvel) < 0.1)
        xvel = yvel = 0;
//! [5]

//! [6]
    QRectF sceneRect = scene()->sceneRect();
    newPos = pos() + QPointF(xvel, yvel);
    newPos.setX(qMin(qMax(newPos.x(), sceneRect.left() + 10), sceneRect.right() - 10));
    newPos.setY(qMin(qMax(newPos.y(), sceneRect.top() + 10), sceneRect.bottom() - 10));
}
//! [6]

//! [7]
bool ViewNode::advancePosition()
{
    if (newPos == pos())
        return false;

    setPos(newPos);
    return true;
}
//! [7]

//! [8]
QRectF ViewNode::boundingRect() const
{
    qreal adjust = 2;
    return QRectF( -(width/2) - adjust, -(height/2) - adjust, (width+3) + adjust, (height+3) + adjust);
}
//! [8]

//! [9]
QPainterPath ViewNode::shape() const
{
    QPainterPath path;
    path.addEllipse(-(width/2), -(height/2), width, height);
    return path;
}
//! [9]

//! [10]
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
        painter->setBrush(Qt::white);

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

//! [10]

//! [11]
QVariant ViewNode::itemChange(GraphicsItemChange change, const QVariant &value)
{
    switch (change) {
    case ItemPositionHasChanged:
        for (ViewEdge *edge : qAsConst(edgeList))
            edge->adjust();
        graph->itemMoved();
        break;
    default:
        break;
    };

    return QGraphicsItem::itemChange(change, value);
}
//! [11]

//! [12]
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
//! [12]
