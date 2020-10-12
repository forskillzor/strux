#include "binarytreenode.h"

BTNode::BTNode(int val)
    :Node(val)
{
    value = val;
}

BTNode::~BTNode()
{
    delete this;
}

void BTNode::addItem(ModelItem *item)
{
    ++level;
    BTNode* node = static_cast<BTNode*>(item);
    node->level++;

    if (node->getValue() < value) {
        if (left) {
            left->addItem(item);
        }
        else {
            left = static_cast<BTNode*>(item);
            left->setParent(this);
            return;
        }
    }
    else if (node->getValue() >= value) {
        if (right){
            right->addItem(item);
        }
        else {
            right = static_cast<BTNode*>(item);
            right->setParent(this);
            return;
        }
    }
}
