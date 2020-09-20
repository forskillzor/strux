#ifndef BTNODE_H
#define BTNODE_H


class BTNode
{
    int value;
    BTNode *parent;
    BTNode *left;
    BTNode *right;

public:
    BTNode(int val);
    BTNode(BTNode *parent, int val);

    void addChild(BTNode *child);
    void addLeft(BTNode *child) { left = child; }
    void addRight(BTNode *child) { right = child; }
};

#endif // BTNODE_H
