#include "model.h"
#include <QDebug>

/*
 * Factory
 */

Model* Model::createModel(ModelType type)
{
    switch (type) {
        case ModelType::Tree:
            return new TreeModel();
    }
}

/* Implementations TreeModel
 */

TreeModel::TreeModel() : Model()
{
}

void TreeModel::addItem(ModelItem *item)
{
        if (root)
        root->addItem(item);
    else {
        root = static_cast<BinaryTreeNode*>(item);
    }
}

void TreeModel::removeItem()
{
}

ModelItem *TreeModel::getRoot()
{
    ModelItem* item = static_cast<BinaryTreeNode*>(root);
    return item;
}

/* Implementations BinaryTreeNode
 */

BinaryTreeNode::BinaryTreeNode(int val) : ModelItem()
{
    value = val;
}

void BinaryTreeNode::setParent(ModelItem *pparent)
{
    BinaryTreeNode* node = static_cast<BinaryTreeNode*>(pparent);
    qDebug() << "setParent:" << pparent->getValue();
    parent = node;
}

void BinaryTreeNode::addItem(ModelItem *item)
{
    BinaryTreeNode* node = static_cast<BinaryTreeNode*>(item);

    if (node->getValue() < value) {
        if (left) {
            left->addItem(node);
        }
        else {
            // TODO new ViewNode() new Edge()
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
            // TODO new ViewNode() new Edge()
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
