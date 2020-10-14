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
    ++node->level;

    if (item->value < value) {
        if (left)
            left->addItem(item);
        else {
            left = node;
            left->setParent(this);
        }
    }
    else {
        if (right)
            right->addItem(item);
        else {
            right = node;
            right->setParent(this);
        }
    }

}
