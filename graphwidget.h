#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QGraphicsView>
#include "edge.h"

class Model;
class BTNode;
class Node;
class ViewModel;
class Algorithm;

class Observer {

};

class GraphWidget : public QGraphicsView, public Observer
{
    Q_OBJECT

public:
    GraphWidget(QWidget *parent = nullptr);

    void itemMoved();
    void resetView();

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
    Node *centerNode = nullptr;
    QGraphicsScene *aScene = nullptr;

    QVector<QString> labels{ "one", "two", "three", "four", "five" };
    QVector<Node *> nodes;
    QVector<Edge *> edges;

    ViewModel *viewModel = nullptr;
    Model *model = nullptr;
    Algorithm *algorithm = nullptr;
};

#endif // GRAPHWIDGET_H
