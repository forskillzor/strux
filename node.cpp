#include "edge.h"
#include "node.h"
#include "graphwidget.h"

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOption>

ViewNode::ViewNode(GraphWidget *graphWidget, QString &l)
    : label(l), graph(graphWidget)
{
    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(DeviceCoordinateCache);
    setAcceptHoverEvents(true);
    setZValue(-1);
    width = 40;
    height = 40;
}

void ViewNode::addEdge(Edge *edge)
{
    edgeList << edge;
    edge->adjust();
}

QVector<Edge *> ViewNode::edges() const
{
    return edgeList;
}

void ViewNode::calculateForces()
{
    if (!scene() || scene()->mouseGrabberItem() == this) {
        newPos = pos();
        return;
    }

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

    // Now subtract all forces pulling items together
    double weight = (edgeList.size() + 1) * 10;
    for (const Edge *edge : qAsConst(edgeList)) {
        QPointF vec;
        if (edge->sourceNode() == this)
            vec = mapToItem(edge->destNode(), 0, 0);
        else
            vec = mapToItem(edge->sourceNode(), 0, 0);
        xvel -= vec.x() / weight;
        yvel -= vec.y() / weight;
    }

    if (qAbs(xvel) < 0.1 && qAbs(yvel) < 0.1)
        xvel = yvel = 0;

    QRectF sceneRect = scene()->sceneRect();
    newPos = pos() + QPointF(xvel, yvel);
    newPos.setX(qMin(qMax(newPos.x(), sceneRect.left() + 10), sceneRect.right() - 10));
    newPos.setY(qMin(qMax(newPos.y(), sceneRect.top() + 10), sceneRect.bottom() - 10));
}

bool ViewNode::advancePosition()
{
    if (newPos == pos())
        return false;

    setPos(newPos);
    return true;
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


QVariant ViewNode::itemChange(GraphicsItemChange change, const QVariant &value)
{
    switch (change) {
    case ItemPositionHasChanged:
        for (Edge *edge : qAsConst(edgeList))
            edge->adjust();
        graph->itemMoved();
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
