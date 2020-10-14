#pragma once

#include <QObject>
#include <QGraphicsObject>
#include <QGraphicsItem>
#include "model.h"

class Edge;
class QPropertyAnimation;

class Node : public QGraphicsObject, public ModelItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
    Q_PROPERTY(qreal scale READ scale WRITE setScale);
public:
    static QGraphicsScene* scene;
    static void setScene(QGraphicsScene *value);

    explicit Node(int val);

    void setParent(ModelItem* pparent) override;
    void addItem(ModelItem* pitem) override;
    void removeItem() override;
    int getValue() override { return value; }
    void setValue(int val) override { value = val; }

    void startAnimation() override;

    int type() const override { return Type; }

    void addEdge(Edge *edge);
    QVector<Edge *> edges() const;

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    int getWidth() const { return width; }
    int getHeight() const { return height; }

    void setWidth(int w) { width = w; }
    void setHeight(int h) { height = h; }


    QString label;
    enum { Type = UserType + 1 };
    int hardX = 0;
    int hardY = 0;

    int level = 0;

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    int width;
    int height;

    QVector<Edge *> edgeList;
    QPointF newPos;

    QPropertyAnimation* scaleAnimation;

    Qt::GlobalColor background;
signals:
    void animationFinished();

};
