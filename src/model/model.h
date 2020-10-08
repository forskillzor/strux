#ifndef TREEMODEL_H
#define TREEMODEL_H

#include <QVector>
#include <QRandomGenerator>
#include <QTime>
#include <QGraphicsScene>

#include "../model/model.h"
#include "../view/viewnode.h"

enum class ModelType { Empty = 0, Tree };

class ModelItem;
class BinaryTreeNode;
class GraphWidget;

/*
 * Interface Model
 */

class Model
{
protected:
    GraphWidget* graph = nullptr;
    ModelItem *root = nullptr;
    ModelType type = ModelType::Empty;

public:
    static Model* createModel(ModelType type, GraphWidget* pwidget);

    Model(GraphWidget* pwidget);
    QVector<int>* generateData();
    virtual ModelItem* createItem(int value);
    virtual void addItem(ModelItem *node) = 0;
    virtual void removeItem() = 0;
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

protected:
    int value;
};

/*
 * Implementations BinaryTree Model
 */

class TreeModel : public Model
{
public:
    explicit TreeModel(GraphWidget* pwidget);
    void addItem(ModelItem *node) override;
    void removeItem() override;
};

/*
 * Implementations BinaryTree Node
 */

//TODO inheritance QObject and other features
class BinaryTreeNode : public ModelItem
{
public:

    BinaryTreeNode(int val);
    ~BinaryTreeNode() override;
    void setParent(ModelItem *prarent) override;
    void addItem(ModelItem *node) override;
    void removeItem() override;
    int getValue() override { return value; };
    void setValue(int val) override { value = val; };

    BinaryTreeNode* parent = nullptr;
    BinaryTreeNode* left = nullptr;
    BinaryTreeNode* right = nullptr;

    int level = 1;
    int count;
};


#endif // TREEMODEL_H
