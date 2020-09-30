#ifndef NODE_H
#define NODE_H

#include <QGraphicsItem>
#include <QVector>
#include <QString>
#include <QObject>


class ViewNode;
class ViewEdge;
class GraphWidget;

class ViewEdge : public QGraphicsItem
{
public:
    ViewEdge(ViewNode *sourceNode, ViewNode *destNode);

    ViewNode *sourceNode() const;
    ViewNode *destNode() const;

    void adjust();

    enum { Type = UserType + 2 };
    int type() const override { return Type; }

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    ViewNode *source, *dest;

    QPointF sourcePoint;
    QPointF destPoint;
    qreal arrowSize = 5;
};


#endif // NODE_H
