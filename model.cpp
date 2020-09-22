#include "model.h"
#include "globalstate.h"
#include <QDebug>

extern ApplicationState appState;
class Algorithm;

/*******************************
 *
 *******************************/

Model* Model::createModel(ModelType type)
{
    switch (type) {
        case ModelType::Tree:
            return new TreeModel();
    }
}

/*******************************
 * Interface ModelElement
 *******************************/

ModelItem::ModelItem()
{
    algorithm = appState.algorithm;
}

/*******************************
 * Implementations TreeModel
 *******************************/

TreeModel::TreeModel() : Model()
{
}

void TreeModel::addItem(ViewNode *node)
{
}

void TreeModel::removeItem()
{
}

/*******************************
 * Implementations BinaryTreeNode
 *******************************/

BinaryTreeNode::BinaryTreeNode(int val) : ModelItem()
{
    value = val;
}

void BinaryTreeNode::addItem(ModelItem *pelement)
{
    algorithm->addItem(this, pelement);
}

void BinaryTreeNode::removeItem()
{
}

