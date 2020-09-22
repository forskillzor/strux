#include "algorithm.h"

/*******************************
 * Interface
 *******************************/

Algorithm *Algorithm::createAlgorithm(AlgorithmType type)
{
    switch(type){
    case AlgorithmType::BinaryTree:
        return new BinaryTreeAlgorytm();
    }
}

Algorithm::Algorithm()
{
}

/*******************************
 * Implementations
 *******************************/

BinaryTreeAlgorytm::BinaryTreeAlgorytm() : Algorithm()
{
}

void BinaryTreeAlgorytm::apply()
{
}

void BinaryTreeAlgorytm::addItem(Node* node)
{
    if (node->getValue() < item->value) {
        if (item->left)
           item->left->algorithm->addItem(node);
        else {
           item->left = node;
        }

    }
    else {
        if (item->right)
            item->right->algorithm->addItem(node);
        else {
            item->left = node;
        }
    }
}
