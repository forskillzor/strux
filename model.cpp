#include "model.h"
#include "modelnode.h"

/*******************************
 * Interface Model
 *******************************/

Model::Model()
{
    for (int val : data)
        nodes.push_back(new BTNode(val));
}

void Model::addItem(BTNode *node)
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
