#ifndef NODE_H
#define NODE_H

#include <QGraphicsItem>
#include <QVector>
#include <QString>


class Node;
class Edge;
class GraphWidget;
class Algorithm;

class Node : public QGraphicsItem
{
public:
    Node(GraphWidget *graphWidget, QString &label);

    QString label;
    int value;
    Node* left;
    Node* right;
    Algorithm* algorithm = nullptr;

    void addEdge(Edge *edge);
    QVector<Edge *> edges() const;

    enum { Type = UserType + 1 };
    int type() const override { return Type; }

    void calculateForces();
    bool advancePosition();

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void setHeight(int h) { height = h; }
    int getHeight() { return height; }
    void setWidth(int w) { width = w; }
    int getWidth() { return width; }
    int getValue() {return value; }

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QVector<Edge *> edgeList;
    QPointF newPos;
    GraphWidget *graph;
    int width;
    int height;
};

#endif // NODE_H
