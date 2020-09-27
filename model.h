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
    ModelItem *root = nullptr;
//    QVector<int> *data;
    QVector<ModelItem*> items;
protected:
    ModelType type = ModelType::Empty;
public:
    Model();
    static Model* createModel(ModelType type);
    static QVector<int>* generateData();
    virtual void addItem(ModelItem *node) = 0;
    virtual void removeItem() = 0;
    virtual ModelItem* getRoot() = 0;
    virtual ModelType getType() = 0;
    void readData(QVector<int>* pdata);
    void clear();
    QVector<int>* data;// { 'b', 's', 'z', 'w', 'a', 'i', 'o','t','v'};
};

/*
 * Interface ModelElement
 * Abstract class for node or glyphs items of model
 */

class ModelItem
{

public:
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

private:
    QVector<ModelItem*> nodes;
    BinaryTreeNode *root = nullptr;
};


/*
 * Implementations BinaryTree Node
 */

class BinaryTreeNode : public ModelItem
{
public:
    BinaryTreeNode(int val);
    void setParent(ModelItem *prarent) override;
    void addItem(ModelItem *node) override;
    void removeItem() override;
    int getValue() override { return value; };
    void setValue(int val) override { value = val; };

    int level = 1;
    BinaryTreeNode* parent = nullptr;
    BinaryTreeNode* left = nullptr;
    BinaryTreeNode* right = nullptr;
    int count;
private:
};


#endif // TREEMODEL_H
