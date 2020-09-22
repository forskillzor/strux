#include "algorithm.h"
#include "model.h"

class BinaryTreeNode;

/*******************************
 * Factory Method
 *******************************/

Algorithm *Algorithm::createAlgorithm(AlgorithmType type)
{
    switch(type){
    case AlgorithmType::BinaryTree:
        return new BinaryTreeAlgorytm();
    }
}

/*******************************
 * BinaryTreeAlgorithm
 *******************************/

BinaryTreeAlgorytm::BinaryTreeAlgorytm() : Algorithm()
{
}

void BinaryTreeAlgorytm::apply()
{
}

void BinaryTreeAlgorytm::addItem(ModelItem *self, ModelItem* node)
{
    BinaryTreeNode* belem;
    BinaryTreeNode* bnode;

    belem = dynamic_cast<BinaryTreeNode*>(self);
    if (node->getValue() < self->getValue()) {
        if (belem->left)
           belem->left->algorithm->addItem(belem, node);
        else {
           belem->left = bnode;
        }

    }
    else {
        if (belem->right)
            belem->right->algorithm->addItem(belem, bnode);
        else {
            belem->left = bnode;
        }
    }
}
