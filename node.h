#ifndef NODE_H
#define NODE_H

#include <QGraphicsItem>
#include <QVector>
#include <QString>


class ViewNode;
class Edge;
class GraphWidget;
class Algorithm;

class ViewItem {

};

class ViewNode : public QGraphicsItem, public ViewItem
{
public:
    ViewNode(GraphWidget *graphWidget, QString &label);

    QString label;
    ViewNode* left;
    ViewNode* right;
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

    int getWidth() { return width; }
    int getHeight() { return height; }

    void setWidth(int w) { width = w; }
    void setHeight(int h) { height = h; }

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