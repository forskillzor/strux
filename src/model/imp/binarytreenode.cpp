#include <QDebug>

#include "binarytreenode.h"


BTNode::BTNode(int val)
    : Node(val)
{
}

BTNode::~BTNode()
{
    delete this;
}

void BTNode::addItem(ModelItem *item)
{
    BTNode* node = static_cast<BTNode*>(item);
    BTNode* nextNode = nullptr;
    ++node->level;

    if (node->value < value)
        nextNode = this->left;
    else
        nextNode = this->right;

    if (nextNode)
        nextNode->addItem(item);
    else {
        nextNode = node;
        nextNode->setParent(this);
    }

//    if (item->value < value) {
//        if (left)
//            left->addItem(item);
//        else {
//            left = node;
//            left->setParent(this);
//        }
//    }
//    else {
//        if (right)
//            right->addItem(item);
//        else {
//            right = node;
//            right->setParent(this);
//        }
//    }

}
