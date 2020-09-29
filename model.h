#ifndef TREEMODEL_H
#define TREEMODEL_H

#include <QVector>
#include <QRandomGenerator>
#include <QTime>

#include "view.h"

class Model;
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
    virtual ModelItem* getRoot() = 0;
    virtual ModelType getType() = 0;
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
    ModelItem* getRoot() override;
    ModelType getType() override;

protected:
    BinaryTreeNode *root = nullptr;
};

/*
 * Implementations BinaryTree Node
 */

class BinaryTreeNode : public ViewNode, public ModelItem
{
//    Q_OBJECT
//    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
public:
    static void connect(BinaryTreeNode* parent, BinaryTreeNode* child);
    BinaryTreeNode(int val, GraphWidget* pwidget);
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
