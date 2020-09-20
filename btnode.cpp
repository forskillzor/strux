#include "btnode.h"

BTNode::BTNode(int val)
    : value(val), parent(nullptr), left(nullptr), right(nullptr)
{
}

//BTNode::BTNode(BTNode *pparent, int val) : value(val), parent(pparent)
//{
//}

void BTNode::addChild(BTNode *child)
{
    if (child->value < value) {
        if (left)
            left->addChild(child);
        else {
            left = child;
        }

    }
    else {
        if (right)
            right->addChild(child);
        else {
            left = child;
        }
    }
}
