#ifndef DRAWER_H
#define DRAWER_H

#include "model.h"

class Drawer
{
protected:
    Model* model = nullptr;
    ModelType type = ModelType::Empty;
    GraphWidget* widget = nullptr;
    QGraphicsScene* scene = nullptr;
public:
    Drawer(Model* pmodel, GraphWidget* pwidget);
    virtual void draw(ModelItem* item = nullptr,
                      ViewNode* vparent = nullptr,
                      qreal x = 0, qreal y = -220);
};

class BinaryTreeDrawer : public Drawer
{
public:
    BinaryTreeDrawer(Model* pmodel, GraphWidget* pwidget);
    void draw(ModelItem* item,
              ViewNode* vparent = nullptr,
              qreal x = 0, qreal y = -220) override;
};

#endif // DRAWER_H
