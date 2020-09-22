#include <math.h>
#include <QKeyEvent>
#include <QRandomGenerator>

#include "graphwidget.h"
#include "edge.h"
#include "node.h"
#include "algorithm.h"

GraphWidget::GraphWidget(QWidget *parent)
    : QGraphicsView(parent)
{
    aScene = new QGraphicsScene(this);
    aScene->setItemIndexMethod(QGraphicsScene::NoIndex);
    aScene->setSceneRect(-400, -400, 800, 800);
    setScene(aScene);
    setCacheMode(CacheBackground);
    setViewportUpdateMode(BoundingRectViewportUpdate);
    setRenderHint(QPainter::Antialiasing);
    setTransformationAnchor(AnchorUnderMouse);
    scale(qreal(0.8), qreal(0.8));
    setMinimumSize(400, 400);
    setWindowTitle(tr("Elastic Nodes"));

    for (QString &label : labels) {
        nodes.push_back(new ViewNode(this, label));
    }
    for(int i = 1; i < nodes.length(); ++i) {
        edges.push_back(new Edge(nodes[i-1], nodes[i]));
    }
    for (ViewNode *node : nodes) {
        aScene->addItem(node);
    }
    for (Edge *edge : edges) {
        aScene->addItem(edge);
    }
    qreal x(-200);
    qreal y(-200);
    for (ViewNode *node : nodes) {
        node->setPos(x, y);
        x+=100, y+=100;
    }

}

void GraphWidget::itemMoved()
{
    if (!timerId)
        timerId = startTimer(1000 / 25);
}

void GraphWidget::resetView()
{
    qreal x(-200);
    qreal y(-200);
    for (ViewNode *node : nodes) {
        node->setPos(x, y);
        x+=100, y+=100;
    }
}

void GraphWidget::keyPressEvent(QKeyEvent *event)
{
    /*
    switch (event->key()) {
    case Qt::Key_Up:
        centerNode->moveBy(0, -20);
        break;
    case Qt::Key_Down:
        centerNode->moveBy(0, 20);
        break;
    case Qt::Key_Left:
        centerNode->moveBy(-20, 0);
        break;
    case Qt::Key_Right:
        centerNode->moveBy(20, 0);
        break;
    case Qt::Key_Plus:
        zoomIn();
        break;
    case Qt::Key_Minus:
        zoomOut();
        break;
    case Qt::Key_Space:
    case Qt::Key_Enter:
        shuffle();
        break;
    default:
        QGraphicsView::keyPressEvent(event);
    }
    */
}

void GraphWidget::timerEvent(QTimerEvent *event)
{
    /*
    Q_UNUSED(event);

    QVector<Node *> nodes;
    const QList<QGraphicsItem *> items = scene()->items();
    for (QGraphicsItem *item : items) {
        if (Node *node = qgraphicsitem_cast<Node *>(item))
            nodes << node;
    }

    for (Node *node : qAsConst(nodes))
        node->calculateForces();

    bool itemsMoved = false;
    for (Node *node : qAsConst(nodes)) {
        if (node->advancePosition())
            itemsMoved = true;
    }

    if (!itemsMoved) {
        killTimer(timerId);
        timerId = 0;
    }
    */
}

#if QT_CONFIG(wheelevent)
void GraphWidget::wheelEvent(QWheelEvent *event)
{
    scaleView(pow(2., -event->angleDelta().y() / 240.0));
}
#endif

void GraphWidget::drawBackground(QPainter *painter, const QRectF &rect)
{
    Q_UNUSED(rect);

    // Shadow
    QRectF sceneRect = this->sceneRect();
    // if (rightShadow.intersects(rect) || rightShadow.contains(rect))
    //     painter->fillRect(rightShadow, Qt::darkGray);
    // if (bottomShadow.intersects(rect) || bottomShadow.contains(rect))
    //     painter->fillRect(bottomShadow, Qt::darkGray);

    // Fill
    // QLinearGradient gradient(sceneRect.topLeft(), sceneRect.bottomRight());
    // gradient.setColorAt(0, Qt::white);
    // gradient.setColorAt(1, Qt::lightGray);
    painter->fillRect(rect.intersected(sceneRect), Qt::white);
    painter->setPen(Qt::lightGray);
    painter->setBrush(Qt::NoBrush);
    painter->drawRect(sceneRect);

    // Text
    QRectF textRect(sceneRect.left() + 4, sceneRect.top() + 4,
                    sceneRect.width() - 4, sceneRect.height() - 4);
    // QString message(tr("Click and drag the nodes around, and zoom with the mouse "
    //                  "wheel or the '+' and '-' keys"));

    QFont font = painter->font();
    font.setBold(true);
    font.setPointSize(14);
    painter->setFont(font);
    painter->setPen(Qt::lightGray);
//    painter->drawText(textRect.translated(2, 2), message);
    painter->setPen(Qt::black);
//    painter->drawText(textRect, message);
}

void GraphWidget::scaleView(qreal scaleFactor)
{
    qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    if (factor < 0.07 || factor > 100)
        return;

    scale(scaleFactor, scaleFactor);
}



void GraphWidget::shuffle()
{
    const QList<QGraphicsItem *> items = scene()->items();
    for (QGraphicsItem *item : items) {
        if (qgraphicsitem_cast<ViewNode *>(item))
            item->setPos(-150 + QRandomGenerator::global()->bounded(300), -150 + QRandomGenerator::global()->bounded(300));
    }
}

void GraphWidget::zoomIn()
{
    scaleView(qreal(1.2));
}

void GraphWidget::zoomOut()
{
    scaleView(1 / qreal(1.2));
}
