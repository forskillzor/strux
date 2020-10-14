#pragma once

#include <model/node.h>

class BTNodeBalanced : public Node
{
public:
    BTNodeBalanced(int val);
    ~BTNodeBalanced() override;
    void addItem(ModelItem* item) override;

    BTNodeBalanced* parent = nullptr;
    BTNodeBalanced* left = nullptr;
    BTNodeBalanced* right = nullptr;
};
