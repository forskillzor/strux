#pragma once

#include <QVector>
#include <QRandomGenerator>
#include <QTime>
#include <QGraphicsScene>
#include <QPropertyAnimation>

enum class ModelType { Empty = 0, Tree, BalancedTree };

class ModelItem;
class GraphWidget;

/*
 * Interface Model
 */

class Model
{
protected:
    ModelItem *root = nullptr;
    ModelType type = ModelType::Empty;

public:
    static Model* createModel(ModelType type);

    virtual ModelItem* createItem(int value);
    virtual void addItem(ModelItem *node);
    virtual void removeItem() = 0;
    virtual void setRoot(ModelItem* item) = 0;

    Model();
    QVector<int>* generateData();
    ModelItem* getRoot() { return root; }
    ModelType getType() { return type; }
    void readData(QVector<int>* pdata);
    void clear();
    QVector<int>* inputData;
};

/*
 * Interface ModelElement
 * Abstract class for node or glyphs items of model
 */

class ModelItem
{

public:
    static Model* model;
    virtual ~ModelItem();
    virtual void setParent(ModelItem* pprarent) = 0;
    virtual void addItem(ModelItem* pitem) = 0;
    virtual void removeItem() = 0;
    virtual int getValue() = 0;
    virtual void setValue(int val) = 0;
    virtual void startAnimation() = 0;
    int value;
    QPointF *coordinate;
    QPropertyAnimation* moveAnimation = nullptr;
};
