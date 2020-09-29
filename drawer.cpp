#include <QDebug>

#include "graphwidget.h"
#include "drawer.h"
#include "view.h"
#include "model.h"

Drawer::Drawer(Model* pmodel, GraphWidget* pwidget)
     :model(pmodel),
      type(pmodel->getType()),
      widget(pwidget),
      scene(pwidget->scene())
{
}

Drawer *Drawer::createDrawer(Model *pmodel, GraphWidget *pwidget)
{
    switch (pmodel->getType()) {
    case ModelType::Empty:
        return nullptr;
    case ModelType::Tree:
        return new BinaryTreeDrawer(pmodel, pwidget);
    }
}

Drawer::~Drawer()
{
}

void Drawer::draw()
{
}

void Drawer::drawItem(ModelItem *item, ViewNode *vparent, qreal x, qreal y)
{
}

BinaryTreeDrawer::BinaryTreeDrawer(Model* pmodel, GraphWidget* pwidget)
    :Drawer(pmodel, pwidget)
{
}

void BinaryTreeDrawer::draw()
{
    drawItem(model->getRoot());
}

void BinaryTreeDrawer::drawItem (ModelItem *item,
                            ViewNode* vparent,
                            qreal x,
                            qreal y)
{
    static int xshift = 200;
    static int yshift = 50;

    if (item) {
        BinaryTreeNode* node = static_cast<BinaryTreeNode*>(item);
        ViewNode *vnode = new ViewNode(node->getValue(), widget);

        vnode->setPos(x, y);

        if (vparent) {
            ViewEdge *edge = new ViewEdge(vnode, vparent);
            scene->addItem(edge);
        }

        if (node->left) {
            drawItem(node->left, vnode, (x-xshift/node->level), y+yshift);
        }
        if (node->right) {
            drawItem(node->right, vnode, (x+xshift/node->level), y+yshift);
        }
    }
    else
        return;
}
