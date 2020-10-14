#include "btnodebalanced.h"

BTNodeBalanced::BTNodeBalanced(int val)
    : Node(val)
{
}

BTNodeBalanced::~BTNodeBalanced()
{
    delete this;
}

void BTNodeBalanced::addItem(ModelItem *item)
{
    BTNodeBalanced* node = static_cast<BTNodeBalanced*>(item);
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
