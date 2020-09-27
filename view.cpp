#include "view.h"
#include "graphwidget.h"

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOption>
#include <QtMath>

ViewEdge::ViewEdge(ViewNode *sourceNode, ViewNode *destNode)
    : source(sourceNode), dest(destNode)
{
    setAcceptedMouseButtons(Qt::NoButton);
    source->addEdge(this);
    dest->addEdge(this);
    adjust();
}

ViewNode *ViewEdge::sourceNode() const
{
    return source;
}

ViewNode *ViewEdge::destNode() const
{
    return dest;
}

void ViewEdge::adjust()
{
    if (!source || !dest)
        return;

    QLineF line(mapFromItem(source, 0, 0), mapFromItem(dest, 0, 0));
    qreal length = line.length();

    prepareGeometryChange();

    if (length > qreal(20.)) {
        QPointF edgeOffset((line.dx() * (source->getWidth()/2)) / length, (line.dy() * (source->getHeight()/2)) / length);
        sourcePoint = line.p1() + edgeOffset;
        destPoint = line.p2() - edgeOffset;
    } else {
        sourcePoint = destPoint = line.p1();
    }
}

QRectF ViewEdge::boundingRect() const
{
    if (!source || !dest)
        return QRectF();

    qreal penWidth = 1;
    qreal extra = (penWidth + arrowSize) / 2.0;

    return QRectF(sourcePoint, QSizeF(destPoint.x() - sourcePoint.x(),
                                      destPoint.y() - sourcePoint.y()))
        .normalized()
        .adjusted(-extra, -extra, extra, extra);
}

void ViewEdge::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    if (!source || !dest)
        return;

    QLineF line(sourcePoint, destPoint);
    if (qFuzzyCompare(line.length(), qreal(0.)))
        return;

    // Draw the line itself
    painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter->drawLine(line);

    // Draw the arrows
    double angle = std::atan2(-line.dy(), line.dx());

    QPointF sourceArrowP1 = sourcePoint + QPointF(sin(angle + M_PI / 3) * arrowSize,
                                                  cos(angle + M_PI / 3) * arrowSize);
    QPointF sourceArrowP2 = sourcePoint + QPointF(sin(angle + M_PI - M_PI / 3) * arrowSize,
                                                  cos(angle + M_PI - M_PI / 3) * arrowSize);
    QPointF destArrowP1 = destPoint + QPointF(sin(angle - M_PI / 3) * arrowSize,
                                              cos(angle - M_PI / 3) * arrowSize);
    QPointF destArrowP2 = destPoint + QPointF(sin(angle - M_PI + M_PI / 3) * arrowSize,
                                              cos(angle - M_PI + M_PI / 3) * arrowSize);

    painter->setBrush(Qt::black);
    painter->drawPolygon(QPolygonF() << line.p1() << sourceArrowP1 << sourceArrowP2);
    painter->drawPolygon(QPolygonF() << line.p2() << destArrowP1 << destArrowP2);
}

ViewNode::ViewNode(QString &l)
    : label(l), width(40), height(40)
{
    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(DeviceCoordinateCache);
    setAcceptHoverEvents(true);
    setZValue(-1);
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

