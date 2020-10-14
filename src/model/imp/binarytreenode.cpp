#include <QDebug>

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

    BTNode* targetNode = selection(item);
    if (targetNode)
        targetNode->addItem(item);
    else {
        targetNode = static_cast<BTNode*>(item);
        targetNode->setParent(this);
    }
}

BTNode* BTNode::selection(ModelItem *item)
{
    BTNode* node = static_cast<BTNode*>(item);
    if (node->value < value)
        return left;
    else
        return right;
}
