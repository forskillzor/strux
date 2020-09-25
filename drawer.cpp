#include <QDebug>

#include "graphwidget.h"
#include "drawer.h"
#include "node.h"
#include "edge.h"
#include "model.h"

DrawRequest::DrawRequest(Model *pmodel, ModelType t, GraphWidget* pwidget)
    : model(pmodel), type(t), widget(pwidget)
{
}

Drawer::Drawer(DrawRequest* req)
     :type(req->type),
      model(req->model),
      widget(req->widget),
      scene(req->widget->getScene()),
      request(req)
{
}

void Drawer::draw(ModelItem *item, ViewNode *vparent, qreal x, qreal y)
{
    switch(type) {
    case ModelType::Tree:
        BinaryTreeDrawer* drawer = new BinaryTreeDrawer(request);
        drawer->draw(static_cast<BinaryTreeNode*>(request->model->getRoot()));
        break;
    }
}

BinaryTreeDrawer::BinaryTreeDrawer(DrawRequest* req)
    : Drawer(req)
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
        ViewNode *vnode = new ViewNode(widget, label);
        vnode->setPos(x, y);
        //BUG scene 0x0
        scene->addItem(vnode);

        if (vparent) {
            Edge *edge = new Edge(vnode, vparent);
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

