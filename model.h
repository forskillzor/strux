#ifndef TREEMODEL_H
#define TREEMODEL_H

#include <QVector>
#include "algorithm.h"

enum class ModelType { Tree = 1 };

class ViewNode;
class ModelItem;

/*******************************
 * Interface Model
 *******************************/

class Model
{
    ModelItem *root = nullptr;

    QVector<int> *data;
    QVector<ModelItem*> items;
public:

    static Model* createModel(ModelType type);
    virtual void addItem(ViewNode *node) = 0;
    virtual void removeItem() = 0;

};

/*******************************
 * Interface ModelElement
 *******************************/

class ModelItem
{

public:
    ModelItem();
    virtual void addItem(ModelItem*) = 0;
    virtual void removeItem() = 0;
    virtual int getValue() = 0;
    virtual void setValue(int val) = 0;

    Algorithm* algorithm;
};

/*******************************
 * Implementations BinaryTree Model
 *******************************/

class TreeModel : public Model
{
public:
    explicit TreeModel();
    void addItem(ViewNode *node) override;
    void removeItem() override;
    QVector<ModelItem*> nodes;
};

#endif // TREEMODEL_H

/*******************************
 * Implementations BinaryTree Node
 *******************************/

class BinaryTreeNode : public ModelItem
{
public:
    BinaryTreeNode(int val);
    void addItem(ModelItem *pelement) override;
    void removeItem() override;

    BinaryTreeNode* parent;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    int value;
};
