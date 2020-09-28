#ifndef TREEMODEL_H
#define TREEMODEL_H

#include <QVector>
#include <QRandomGenerator>
#include <QTime>

#include "view.h"

class Model;
enum class ModelType { Empty = 0, Tree };

class ViewNode;
class ModelItem;
class BinaryTreeNode;

/*
 * Interface Model
 */

class Model
{
protected:
    ModelItem *root = nullptr;
    ModelType type = ModelType::Empty;
public:
    Model();
    static Model* createModel(ModelType type);
    QVector<int>* generateData();
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
    explicit TreeModel();
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

class BinaryTreeNode : public ModelItem
{
public:
    BinaryTreeNode(int val);
    ~BinaryTreeNode();
    void setParent(ModelItem *prarent) override;
    void addItem(ModelItem *node) override;
    void removeItem() override;
    int getValue() override { return value; };
    void setValue(int val) override { value = val; };
    BinaryTreeNode* addBTNode(ModelItem* pnode);

    BinaryTreeNode* parent = nullptr;
    BinaryTreeNode* left = nullptr;
    BinaryTreeNode* right = nullptr;

    int level = 1;
    int count;
};


#endif // TREEMODEL_H
