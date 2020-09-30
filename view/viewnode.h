#ifndef VIEWNODE_H
#define VIEWNODE_H

#include <QObject>
#include <QGraphicsItem>

class GraphWidget;
class ViewEdge;
class QPropertyAnimation;

class ViewNode : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
    Q_PROPERTY(qreal scale READ scale WRITE setScale);
public:
    explicit ViewNode(int val, GraphWidget* pwidget);

    QString label;

    void addEdge(ViewEdge *edge);
    QVector<ViewEdge *> edges() const;

    enum { Type = UserType + 1 };
    int type() const override { return Type; }

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void addToGraph(QGraphicsItem* item);

    int getWidth() { return width; }
    int getHeight() { return height; }

    void setWidth(int w) { width = w; }
    void setHeight(int h) { height = h; }

    int hardX;
    int hardY;

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

    QPropertyAnimation* animation;
    QPropertyAnimation* scaleAnimation;

    Qt::GlobalColor background;
public slots:
    void startAnimation();
signals:
    void animationFinished();

};

#endif // VIEWNODE_H
