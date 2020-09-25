#include <QDebug>

#include "graphwidget.h"
#include "drawer.h"
#include "node.h"
#include "edge.h"
#include "model.h"

Drawer::Drawer(Model* pmodel, GraphWidget* pwidget)
     :model(pmodel),
      type(pmodel->getType()),
      widget(pwidget),
      scene(pwidget->getScene())
{
}

void Drawer::draw(ModelItem *item, ViewNode *vparent, qreal x, qreal y)
{
    switch(type) {
    case ModelType::Empty:
        qDebug() << "Empty model";
        break;
    case ModelType::Tree:
        BinaryTreeDrawer* drawer = new BinaryTreeDrawer(model, widget);
        drawer->draw(static_cast<BinaryTreeNode*>(model->getRoot()));
        break;
    }
}

BinaryTreeDrawer::BinaryTreeDrawer(Model* pmodel, GraphWidget* pwidget)
    : Drawer(pmodel, pwidget)
{
}

void BinaryTreeDrawer::draw(ModelItem *item,
                            ViewNode* vparent,
                            qreal x,
                            qreal y)
{
    if (item) {
        BinaryTreeNode* node = static_cast<BinaryTreeNode*>(item);
        QString label = QString::number(node->getValue());
        ViewNode *vnode = new ViewNode(label);
        widget->nodes.push_back(vnode);
        vnode->setPos(x, y);
        scene->addItem(vnode);

        if (vparent) {
            ViewEdge *edge = new ViewEdge(vnode, vparent);
            widget->edges.push_back(edge);
            vnode->setPos(x, y);

            scene->addItem(edge);
        }

        if (node->left) {
            draw(node->left, vnode, x-50, y+50);
        }
        if (node->right) {
            draw(node->right, vnode, x+50, y+50);
        }
    }
    else
        return;
}

