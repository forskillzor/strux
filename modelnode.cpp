#include "modelnode.h"

/*******************************
 * Interface ModelNode
 *******************************/

ModelNode::ModelNode(ModelNode *pparent, int val) : parent(pparent), value(val)
{

}

ModelNode *ModelNode::createNode(NodeType type, int val)
{
    switch (type) {
    case NodeType::Tree:
        return new BTNode(val);
    }
}

/*******************************
 * Implementation
 *******************************/

BTNode::BTNode(int val) : ModelNode(nullptr, val)
{

}

BTNode::BTNode(ModelNode *parent, int val)
{

}

void BTNode::addChild(ModelNode *child)
{
    if (child->getValue() < value) {
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


