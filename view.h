#ifndef NODE_H
#define NODE_H

#include <QGraphicsItem>
#include <QVector>
#include <QString>

#include "model.h"

class ViewNode;
class ViewEdge;
class GraphWidget;
class Algorithm;

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

class ViewNode : public QGraphicsItem
{
public:
    ViewNode(QString &label, GraphWidget* pwidget);

    QString label;

    void addEdge(ViewEdge *edge);
    QVector<ViewEdge *> edges() const;

    enum { Type = UserType + 1 };
    int type() const override { return Type; }

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    int getWidth() { return width; }
    int getHeight() { return height; }

    void setWidth(int w) { width = w; }
    void setHeight(int h) { height = h; }

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QVector<ViewEdge *> edgeList;
    QPointF newPos;
    GraphWidget *graph;
    int width;
    int height;
};

#endif // NODE_H
