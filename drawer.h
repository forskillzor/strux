#ifndef DRAWER_H
#define DRAWER_H

#include "model.h"

struct DrawRequest
{
    DrawRequest(Model* pmodel, ModelType type, GraphWidget* pwidget);
    Model* model;
    ModelType type;
    GraphWidget* widget;
};

class Drawer
{
protected:
    ModelType type;
    Model* model = nullptr;
    GraphWidget* widget = nullptr;
    QGraphicsScene* scene = nullptr;
    DrawRequest *request = nullptr;
public:
    Drawer(DrawRequest* req);
    virtual void draw(ModelItem* item = nullptr,
                      ViewNode* vparent = nullptr,
                      qreal x = 0, qreal y = -220);
};

class BinaryTreeDrawer : public Drawer
{
public:
    BinaryTreeDrawer(DrawRequest* req);
    void draw(ModelItem* item,
              ViewNode* vparent = nullptr,
              qreal x = 0, qreal y = -220) override;
};

#endif // DRAWER_H
