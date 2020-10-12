#pragma once

#include "model/node.h"

class BTNode : public Node
{
public:

    BTNode(int val);
    ~BTNode() override;
    void addItem(ModelItem *node) override;

    BTNode* parent = nullptr;
    BTNode* left = nullptr;
    BTNode* right = nullptr;

};
