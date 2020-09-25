#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QGraphicsView>
#include "edge.h"
#include "model.h"
#include "drawer.h"

class ViewNode;

class GraphWidget : public QGraphicsView
{
    Q_OBJECT

public:
    GraphWidget(QWidget *parent = nullptr);

    void drawModel();
    void reset();
    void itemMoved();
    void addItem(ModelItem* item);
    QGraphicsScene* getScene() { return aScene; }

public slots:
    void shuffle();
    void zoomIn();
    void zoomOut();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void timerEvent(QTimerEvent *event) override;
#if QT_CONFIG(wheelevent)
    void wheelEvent(QWheelEvent *event) override;
#endif
    void drawBackground(QPainter *painter, const QRectF &rect) override;

    void scaleView(qreal scaleFactor);


private:
    int timerId = 0;
    QGraphicsScene *aScene = nullptr;
    Model* model = nullptr;
public:
    QVector<ViewNode *> nodes;
    QVector<ViewEdge *> edges;

};

#endif // GRAPHWIDGET_H
