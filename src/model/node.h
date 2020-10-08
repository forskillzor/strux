#ifndef VIEWNODE_H
#define VIEWNODE_H

#include <QObject>
#include <QGraphicsItem>

class ViewEdge;
class QPropertyAnimation;

class ViewNode : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
    Q_PROPERTY(qreal scale READ scale WRITE setScale);
public:
    static QGraphicsScene* scene;
    static void setScene(QGraphicsScene *value);

    explicit ViewNode(int val);

    QString label;

    void addEdge(ViewEdge *edge);
    QVector<ViewEdge *> edges() const;

    enum { Type = UserType + 1 };
    int type() const override { return Type; }

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    int getWidth() const { return width; }
    int getHeight() const { return height; }

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
