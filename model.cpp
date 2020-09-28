#include "model.h"
#include <QDebug>

/*
 * Factory
 */

Model::Model()
{
    inputData = generateData();
}

Model* Model::createModel(ModelType type)
{
    switch (type) {
        case ModelType::Empty:
            return nullptr;
        case ModelType::Tree:
            return new TreeModel();
    }
}

QVector<int>* Model::generateData()
{
    QVector<int>* result = new QVector<int>;
    QRandomGenerator* generator = new QRandomGenerator;
    QTime timer(QTime::currentTime());
    generator->seed(timer.msecsSinceStartOfDay());
    for (int i = 0; i < 20; ++i) {
        result->push_back(generator->bounded(0,100));
    }
    return result;
}

void Model::readData(QVector<int>* pdata )
{
    for (int val : *pdata) {
        addItem(new BinaryTreeNode(val));
    }
}

void Model::clear()
{
    root = nullptr;
}

/*
 *  Implementations TreeModel
 */

TreeModel::TreeModel() : Model() { type = ModelType::Tree; }

void TreeModel::addItem(ModelItem *item)
{
        if (root)
        root->addItem(item);
    else {
        root = static_cast<BinaryTreeNode*>(item);
    }
}

void TreeModel::removeItem() { }

ModelItem *TreeModel::getRoot() { return root; }

ModelType TreeModel::getType() { return type; }

/*
 * Implementations BinaryTreeNode
 */

BinaryTreeNode::BinaryTreeNode(int val) : ModelItem() { value = val; }

void BinaryTreeNode::setParent(ModelItem *pparent)
{
    BinaryTreeNode* node = static_cast<BinaryTreeNode*>(pparent);
    parent = node;
}

void BinaryTreeNode::addItem(ModelItem *item)
{
    BinaryTreeNode* node = static_cast<BinaryTreeNode*>(item);
    node->level++;

    if (node->getValue() < value) {
        if (left) {
            left->addItem(node);
        }
        else {
            left = static_cast<BinaryTreeNode*>(node);
            left->setParent(this);
            return;
        }
    }
    else if (node->getValue() > value) {
        if (right){
            right->addItem(node);
        }
        else {
            right = static_cast<BinaryTreeNode*>(node);
            right->setParent(this);
            return;
        }
    }
    else
        ++count;
}

void BinaryTreeNode::removeItem()
{
}

