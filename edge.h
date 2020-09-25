#ifndef EDGE_H
#define EDGE_H

#include <QGraphicsItem>

class ViewNode;

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

#endif // EDGE_H
