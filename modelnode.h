#ifndef BTNODE_H
#define BTNODE_H

#include "algorithm.h"

/*******************************
 * Interface ModelNode
 *******************************/

enum class NodeType{Tree = 1};

class ModelNode {
protected:
    Algorithm *algorithm;
    ModelNode *parent;
    int value;
public:
    ModelNode(ModelNode *pparent = nullptr, int val = 0);
    static ModelNode* createNode(NodeType type, int val);
    virtual void addChild(ModelNode*v) = 0;
    virtual int getValue() = 0;
    virtual void setValue(int) = 0;
};

/*******************************
 * Implementation
 *******************************/

class BTNode : public ModelNode
{
    ModelNode *left;
    ModelNode *right;

    void addLeft(BTNode *child) { left = child; }
    void addRight(BTNode *child) { right = child; }

public:
    BTNode(int val);
    BTNode(ModelNode *parent, int val);

    void addChild(ModelNode *child) override;

    int getValue() override { return value; };
    void setValue(int val) override { value = val; };
};


#endif // BTNODE_H
