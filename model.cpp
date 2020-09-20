#include "model.h"
#include "modelnode.h"

/*******************************
 * Interface Model
 *******************************/

Model::Model()
{
    for (int val : data)
        nodes.push_back(ModelNode::createNode(NodeType::Tree, val));
}

Model *Model::createModel(ModelType type)
{
    switch (type) {
        case ModelType::Tree:
            return new TreeModel();
    }
}

void Model::addItem(ModelNode *node)
{
//    if (root == nullptr)
//        root = node;
//    else
//        root->addChild(new BTNode);
}

QVector<int>& Model::getData()
{
    return data;
}

/*******************************
 * Implementations
 *******************************/

TreeModel::TreeModel() : Model()
{
}
